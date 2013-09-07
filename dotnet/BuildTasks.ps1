
Properties {
	$cur_dir = Split-Path $psake.build_script_file
	$src_dir = "$cur_dir\src"
	$pkg_dir = "$cur_dir\nupkg"
	$configuration="Release"
}

Task Default -Depends NugetPack

FormatTaskName {
	param($taskName)
	write-host
	write-host (":"*30) -foregroundcolor Cyan
	write-host "  Executing Task: $taskName" -foregroundcolor Cyan
	write-host (":"*30) -foregroundcolor Cyan
	write-host
}

Task Clean {
	# Delete nupkg dir
	if (Test-Path $pkg_dir -pathType container) { Remove-Item $pkg_dir -Force -Recurse }

	Exec { msbuild "$src_dir\TA-Lib.sln" /t:Clean /p:Configuration=$configuration /nologo }
}

Task Build -Depends Clean {
	Exec { msbuild "$src_dir\TA-Lib.sln" /t:Build /p:Configuration=$configuration /nologo }
}

Task NugetPack {#-Depends Build {
	# Create nupkg dir
	if (-not (Test-Path $pkg_dir -pathType container)) { Exec { New-Item -ItemType Directory -Force -Path "$pkg_dir" } }

	# TA-Lib.nupkg builds from Release binaries only
	Exec { & "$src_dir\.nuget\nuget" pack "$src_dir\TA-Lib.nuspec" -Symbols -OutputDirectory "$pkg_dir" }
}

Task NugetPush {
	Assert (Test-Path $pkg_dir -pathType container) "Nuget directory not found. Run ``build NugetPack`` first."

	$pkgs = Get-ChildItem "$pkg_dir\*.nupkg" -exclude "*.symbols.nupkg" | sort-object -desc lastwritetime
	Assert (($pkgs.count) -gt 0) "Nuget package not found. Run ``build NugetPack`` first."

	if ($pkgs.count -gt 1) { write-host "WARNING! There are" $pkgs.count "nuget packages." -foregroundcolor Yellow }

	$pkg_path = $pkgs[0].FullName
	write-host "Pushing:" $pkg_path -foregroundcolor Cyan
	Exec { & "$src_dir\.nuget\nuget" push "$pkg_path" }
}
