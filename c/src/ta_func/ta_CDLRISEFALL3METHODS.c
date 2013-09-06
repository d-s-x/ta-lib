/* TA-LIB Copyright (c) 1999-2008, Mario Fortier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither name of author nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* List of contributors:
 *
 *  Initial  Name/description
 *  -------------------------------------------------------------------
 *  AC       Angelo Ciceri
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  020605 AC   Creation           
 *
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #include "TA-Lib-Core.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (RetCode::InternalError)
/* Generated */    namespace TicTacTec { namespace TA { namespace Library {
/* Generated */ #elif defined( _JAVA )
/* Generated */    #include "ta_defs.h"
/* Generated */    #include "ta_java_defs.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (RetCode.InternalError)
/* Generated */ #else
/* Generated */    #include <string.h>
/* Generated */    #include <math.h>
/* Generated */    #include "ta_func.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_UTILITY_H
/* Generated */    #include "ta_utility.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_MEMORY_H
/* Generated */    #include "ta_memory.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #define TA_PREFIX(x) TA_##x
/* Generated */ #define INPUT_TYPE   double
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ int Core::CdlRiseFall3MethodsLookback( void )
/* Generated */ 
/* Generated */ #elif defined( _JAVA )
/* Generated */ public int cdlRiseFall3MethodsLookback(  )
/* Generated */ 
/* Generated */ #else
/* Generated */ TA_LIB_API int TA_CDLRISEFALL3METHODS_Lookback( void )
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert local variable here */

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/* Generated */ /* No parameters to validate. */
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/

   /* insert lookback code here. */
    return max( TA_CANDLEAVGPERIOD(BodyShort), TA_CANDLEAVGPERIOD(BodyLong) ) + 4;
}

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/*
 * TA_CDLRISEFALL3METHODS - Rising/Falling Three Methods
 * 
 * Input  = Open, High, Low, Close
 * Output = int
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED ) && defined( USE_SUBARRAY )
/* Generated */ enum class Core::RetCode Core::CdlRiseFall3Methods( int    startIdx,
/* Generated */                                                     int    endIdx,
/* Generated */                                                     SubArray<double>^ inOpen,
/* Generated */                                                     SubArray<double>^ inHigh,
/* Generated */                                                     SubArray<double>^ inLow,
/* Generated */                                                     SubArray<double>^ inClose,
/* Generated */                                                     [Out]int%    outBegIdx,
/* Generated */                                                     [Out]int%    outNBElement,
/* Generated */                                                     SubArray<int>^  outInteger )
/* Generated */ #elif defined( _MANAGED )
/* Generated */ enum class Core::RetCode Core::CdlRiseFall3Methods( int    startIdx,
/* Generated */                                                     int    endIdx,
/* Generated */                                                     cli::array<double>^ inOpen,
/* Generated */                                                     cli::array<double>^ inHigh,
/* Generated */                                                     cli::array<double>^ inLow,
/* Generated */                                                     cli::array<double>^ inClose,
/* Generated */                                                     [Out]int%    outBegIdx,
/* Generated */                                                     [Out]int%    outNBElement,
/* Generated */                                                     cli::array<int>^  outInteger )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public RetCode cdlRiseFall3Methods( int    startIdx,
/* Generated */                                     int    endIdx,
/* Generated */                                     double       inOpen[],
/* Generated */                                     double       inHigh[],
/* Generated */                                     double       inLow[],
/* Generated */                                     double       inClose[],
/* Generated */                                     MInteger     outBegIdx,
/* Generated */                                     MInteger     outNBElement,
/* Generated */                                     int           outInteger[] )
/* Generated */ #else
/* Generated */ TA_LIB_API TA_RetCode TA_CDLRISEFALL3METHODS( int    startIdx,
/* Generated */                                               int    endIdx,
/* Generated */                                                          const double inOpen[],
/* Generated */                                                          const double inHigh[],
/* Generated */                                                          const double inLow[],
/* Generated */                                                          const double inClose[],
/* Generated */                                                          int          *outBegIdx,
/* Generated */                                                          int          *outNBElement,
/* Generated */                                                          int           outInteger[] )
/* Generated */ #endif
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
    ARRAY_LOCAL(BodyPeriodTotal,5);
    int i, outIdx, totIdx, BodyShortTrailingIdx, BodyLongTrailingIdx, lookbackTotal;

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return ENUM_VALUE(RetCode,TA_OUT_OF_RANGE_START_INDEX,OutOfRangeStartIndex);
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return ENUM_VALUE(RetCode,TA_OUT_OF_RANGE_END_INDEX,OutOfRangeEndIndex);
/* Generated */ 
/* Generated */    #if !defined(_JAVA)
/* Generated */    /* Verify required price component. */
/* Generated */    if(!inOpen||!inHigh||!inLow||!inClose)
/* Generated */       return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */ 
/* Generated */    #endif /* !defined(_JAVA)*/
/* Generated */    #if !defined(_JAVA)
/* Generated */    if( !outInteger )
/* Generated */       return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */ 
/* Generated */    #endif /* !defined(_JAVA) */
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

   /* Identify the minimum number of price bar needed
    * to calculate at least one output.
    */

   lookbackTotal = LOOKBACK_CALL(CDLRISEFALL3METHODS)();

   /* Move up the start index if there is not
    * enough initial data.
    */
   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNBElement);
      return ENUM_VALUE(RetCode,TA_SUCCESS,Success);
   }

   /* Do the calculation using tight loops. */
   /* Add-up the initial period, except for the last value. */
   BodyPeriodTotal[4] = 0;
   BodyPeriodTotal[3] = 0;
   BodyPeriodTotal[2] = 0;
   BodyPeriodTotal[1] = 0;
   BodyPeriodTotal[0] = 0;
   BodyShortTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(BodyShort);
   BodyLongTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(BodyLong);
   
   i = BodyShortTrailingIdx;
   while( i < startIdx ) {
        BodyPeriodTotal[3] += TA_CANDLERANGE( BodyShort, i-3 );
        BodyPeriodTotal[2] += TA_CANDLERANGE( BodyShort, i-2 );
        BodyPeriodTotal[1] += TA_CANDLERANGE( BodyShort, i-1 );
        i++;
   }
   i = BodyLongTrailingIdx;
   while( i < startIdx ) {
        BodyPeriodTotal[4] += TA_CANDLERANGE( BodyLong, i-4 );
        BodyPeriodTotal[0] += TA_CANDLERANGE( BodyLong, i );
        i++;
   }
   i = startIdx;

   /* Proceed with the calculation for the requested range.
    * Must have:
    * - first candle: long white (black) candlestick
    * - then: group of falling (rising) small real body candlesticks (commonly black (white)) that hold within 
    *   the prior long candle's range: ideally they should be three but two or more than three are ok too
    * - final candle: long white (black) candle that opens above (below) the previous small candle's close 
    *   and closes above (below) the first long candle's close
    * The meaning of "short" and "long" is specified with TA_SetCandleSettings; here only patterns with 3 small candles
    * are considered;
    * outInteger is positive (1 to 100) or negative (-1 to -100)
    */
   outIdx = 0;

#ifdef TA_LIB_PRO
      /* Section for code distributed with TA-Lib Pro only. */
#else
   do
   {
        if( // 1st long, then 3 small, 5th long
            TA_REALBODY(i-4) > TA_CANDLEAVERAGE( BodyLong, BodyPeriodTotal[4], i-4 ) &&
            TA_REALBODY(i-3) < TA_CANDLEAVERAGE( BodyShort, BodyPeriodTotal[3], i-3 ) &&
            TA_REALBODY(i-2) < TA_CANDLEAVERAGE( BodyShort, BodyPeriodTotal[2], i-2 ) &&
            TA_REALBODY(i-1) < TA_CANDLEAVERAGE( BodyShort, BodyPeriodTotal[1], i-1 ) &&
            TA_REALBODY(i)   > TA_CANDLEAVERAGE( BodyLong, BodyPeriodTotal[0], i ) &&
            // white, 3 black, white  ||  black, 3 white, black
            TA_CANDLECOLOR(i-4) == -TA_CANDLECOLOR(i-3) &&
            TA_CANDLECOLOR(i-3) ==  TA_CANDLECOLOR(i-2) &&
            TA_CANDLECOLOR(i-2) ==  TA_CANDLECOLOR(i-1) &&
            TA_CANDLECOLOR(i-1) == -TA_CANDLECOLOR(i) &&
            // 2nd to 4th hold within 1st: a part of the real body must be within 1st range
            min(inOpen[i-3], inClose[i-3]) < inHigh[i-4] && max(inOpen[i-3], inClose[i-3]) > inLow[i-4] &&
            min(inOpen[i-2], inClose[i-2]) < inHigh[i-4] && max(inOpen[i-2], inClose[i-2]) > inLow[i-4] &&
            min(inOpen[i-1], inClose[i-1]) < inHigh[i-4] && max(inOpen[i-1], inClose[i-1]) > inLow[i-4] &&
            // 2nd to 4th are falling (rising)
            inClose[i-2] * TA_CANDLECOLOR(i-4) < inClose[i-3] * TA_CANDLECOLOR(i-4) &&
            inClose[i-1] * TA_CANDLECOLOR(i-4) < inClose[i-2] * TA_CANDLECOLOR(i-4) &&
            // 5th opens above (below) the prior close
            inOpen[i] * TA_CANDLECOLOR(i-4) > inClose[i-1] * TA_CANDLECOLOR(i-4) &&
            // 5th closes above (below) the 1st close
            inClose[i] * TA_CANDLECOLOR(i-4) > inClose[i-4] * TA_CANDLECOLOR(i-4)
          )
            outInteger[outIdx++] = 100 * TA_CANDLECOLOR(i-4);
        else
            outInteger[outIdx++] = 0;
        /* add the current range and subtract the first range: this is done after the pattern recognition 
         * when avgPeriod is not 0, that means "compare with the previous candles" (it excludes the current candle)
         */
        BodyPeriodTotal[4] += TA_CANDLERANGE( BodyLong, i-4 ) - TA_CANDLERANGE( BodyLong, BodyLongTrailingIdx-4 );
        for (totIdx = 3; totIdx >= 1; --totIdx)
            BodyPeriodTotal[totIdx] += TA_CANDLERANGE( BodyShort, i-totIdx ) 
                                     - TA_CANDLERANGE( BodyShort, BodyShortTrailingIdx-totIdx );
        BodyPeriodTotal[0] += TA_CANDLERANGE( BodyLong, i ) - TA_CANDLERANGE( BodyLong, BodyLongTrailingIdx );

        i++; 
        BodyShortTrailingIdx++;
        BodyLongTrailingIdx++;
   } while( i <= endIdx );
#endif
   /* All done. Indicate the output limits and return. */
   VALUE_HANDLE_DEREF(outNBElement) = outIdx;
   VALUE_HANDLE_DEREF(outBegIdx)    = startIdx;

   return ENUM_VALUE(RetCode,TA_SUCCESS,Success);
}

/**** START GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #undef  TA_LIB_PRO
/* Generated */ #if !defined( _MANAGED ) && !defined( _JAVA )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED ) && defined( USE_SUBARRAY )
/* Generated */ enum class Core::RetCode Core::CdlRiseFall3Methods( int    startIdx,
/* Generated */                                                     int    endIdx,
/* Generated */                                                     SubArray<float>^ inOpen,
/* Generated */                                                     SubArray<float>^ inHigh,
/* Generated */                                                     SubArray<float>^ inLow,
/* Generated */                                                     SubArray<float>^ inClose,
/* Generated */                                                     [Out]int%    outBegIdx,
/* Generated */                                                     [Out]int%    outNBElement,
/* Generated */                                                     SubArray<int>^  outInteger )
/* Generated */ #elif defined( _MANAGED )
/* Generated */ enum class Core::RetCode Core::CdlRiseFall3Methods( int    startIdx,
/* Generated */                                                     int    endIdx,
/* Generated */                                                     cli::array<float>^ inOpen,
/* Generated */                                                     cli::array<float>^ inHigh,
/* Generated */                                                     cli::array<float>^ inLow,
/* Generated */                                                     cli::array<float>^ inClose,
/* Generated */                                                     [Out]int%    outBegIdx,
/* Generated */                                                     [Out]int%    outNBElement,
/* Generated */                                                     cli::array<int>^  outInteger )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public RetCode cdlRiseFall3Methods( int    startIdx,
/* Generated */                                     int    endIdx,
/* Generated */                                     float        inOpen[],
/* Generated */                                     float        inHigh[],
/* Generated */                                     float        inLow[],
/* Generated */                                     float        inClose[],
/* Generated */                                     MInteger     outBegIdx,
/* Generated */                                     MInteger     outNBElement,
/* Generated */                                     int           outInteger[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_CDLRISEFALL3METHODS( int    startIdx,
/* Generated */                                      int    endIdx,
/* Generated */                                      const float  inOpen[],
/* Generated */                                      const float  inHigh[],
/* Generated */                                      const float  inLow[],
/* Generated */                                      const float  inClose[],
/* Generated */                                      int          *outBegIdx,
/* Generated */                                      int          *outNBElement,
/* Generated */                                      int           outInteger[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */     ARRAY_LOCAL(BodyPeriodTotal,5);
/* Generated */     int i, outIdx, totIdx, BodyShortTrailingIdx, BodyLongTrailingIdx, lookbackTotal;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return ENUM_VALUE(RetCode,TA_OUT_OF_RANGE_START_INDEX,OutOfRangeStartIndex);
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return ENUM_VALUE(RetCode,TA_OUT_OF_RANGE_END_INDEX,OutOfRangeEndIndex);
/* Generated */     #if !defined(_JAVA)
/* Generated */     if(!inOpen||!inHigh||!inLow||!inClose)
/* Generated */        return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */     #endif 
/* Generated */     #if !defined(_JAVA)
/* Generated */     if( !outInteger )
/* Generated */        return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */     #endif 
/* Generated */  #endif 
/* Generated */    lookbackTotal = LOOKBACK_CALL(CDLRISEFALL3METHODS)();
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNBElement);
/* Generated */       return ENUM_VALUE(RetCode,TA_SUCCESS,Success);
/* Generated */    }
/* Generated */    BodyPeriodTotal[4] = 0;
/* Generated */    BodyPeriodTotal[3] = 0;
/* Generated */    BodyPeriodTotal[2] = 0;
/* Generated */    BodyPeriodTotal[1] = 0;
/* Generated */    BodyPeriodTotal[0] = 0;
/* Generated */    BodyShortTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(BodyShort);
/* Generated */    BodyLongTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(BodyLong);
/* Generated */    i = BodyShortTrailingIdx;
/* Generated */    while( i < startIdx ) {
/* Generated */         BodyPeriodTotal[3] += TA_CANDLERANGE( BodyShort, i-3 );
/* Generated */         BodyPeriodTotal[2] += TA_CANDLERANGE( BodyShort, i-2 );
/* Generated */         BodyPeriodTotal[1] += TA_CANDLERANGE( BodyShort, i-1 );
/* Generated */         i++;
/* Generated */    }
/* Generated */    i = BodyLongTrailingIdx;
/* Generated */    while( i < startIdx ) {
/* Generated */         BodyPeriodTotal[4] += TA_CANDLERANGE( BodyLong, i-4 );
/* Generated */         BodyPeriodTotal[0] += TA_CANDLERANGE( BodyLong, i );
/* Generated */         i++;
/* Generated */    }
/* Generated */    i = startIdx;
/* Generated */    outIdx = 0;
/* Generated */ #ifdef TA_LIB_PRO
/* Generated */ #else
/* Generated */    do
/* Generated */    {
/* Generated */         if( // 1st long, then 3 small, 5th long
/* Generated */             TA_REALBODY(i-4) > TA_CANDLEAVERAGE( BodyLong, BodyPeriodTotal[4], i-4 ) &&
/* Generated */             TA_REALBODY(i-3) < TA_CANDLEAVERAGE( BodyShort, BodyPeriodTotal[3], i-3 ) &&
/* Generated */             TA_REALBODY(i-2) < TA_CANDLEAVERAGE( BodyShort, BodyPeriodTotal[2], i-2 ) &&
/* Generated */             TA_REALBODY(i-1) < TA_CANDLEAVERAGE( BodyShort, BodyPeriodTotal[1], i-1 ) &&
/* Generated */             TA_REALBODY(i)   > TA_CANDLEAVERAGE( BodyLong, BodyPeriodTotal[0], i ) &&
/* Generated */             // white, 3 black, white  ||  black, 3 white, black
/* Generated */             TA_CANDLECOLOR(i-4) == -TA_CANDLECOLOR(i-3) &&
/* Generated */             TA_CANDLECOLOR(i-3) ==  TA_CANDLECOLOR(i-2) &&
/* Generated */             TA_CANDLECOLOR(i-2) ==  TA_CANDLECOLOR(i-1) &&
/* Generated */             TA_CANDLECOLOR(i-1) == -TA_CANDLECOLOR(i) &&
/* Generated */             // 2nd to 4th hold within 1st: a part of the real body must be within 1st range
/* Generated */             min(inOpen[i-3], inClose[i-3]) < inHigh[i-4] && max(inOpen[i-3], inClose[i-3]) > inLow[i-4] &&
/* Generated */             min(inOpen[i-2], inClose[i-2]) < inHigh[i-4] && max(inOpen[i-2], inClose[i-2]) > inLow[i-4] &&
/* Generated */             min(inOpen[i-1], inClose[i-1]) < inHigh[i-4] && max(inOpen[i-1], inClose[i-1]) > inLow[i-4] &&
/* Generated */             // 2nd to 4th are falling (rising)
/* Generated */             inClose[i-2] * TA_CANDLECOLOR(i-4) < inClose[i-3] * TA_CANDLECOLOR(i-4) &&
/* Generated */             inClose[i-1] * TA_CANDLECOLOR(i-4) < inClose[i-2] * TA_CANDLECOLOR(i-4) &&
/* Generated */             // 5th opens above (below) the prior close
/* Generated */             inOpen[i] * TA_CANDLECOLOR(i-4) > inClose[i-1] * TA_CANDLECOLOR(i-4) &&
/* Generated */             // 5th closes above (below) the 1st close
/* Generated */             inClose[i] * TA_CANDLECOLOR(i-4) > inClose[i-4] * TA_CANDLECOLOR(i-4)
/* Generated */           )
/* Generated */             outInteger[outIdx++] = 100 * TA_CANDLECOLOR(i-4);
/* Generated */         else
/* Generated */             outInteger[outIdx++] = 0;
/* Generated */         BodyPeriodTotal[4] += TA_CANDLERANGE( BodyLong, i-4 ) - TA_CANDLERANGE( BodyLong, BodyLongTrailingIdx-4 );
/* Generated */         for (totIdx = 3; totIdx >= 1; --totIdx)
/* Generated */             BodyPeriodTotal[totIdx] += TA_CANDLERANGE( BodyShort, i-totIdx ) 
/* Generated */                                      - TA_CANDLERANGE( BodyShort, BodyShortTrailingIdx-totIdx );
/* Generated */         BodyPeriodTotal[0] += TA_CANDLERANGE( BodyLong, i ) - TA_CANDLERANGE( BodyLong, BodyLongTrailingIdx );
/* Generated */         i++; 
/* Generated */         BodyShortTrailingIdx++;
/* Generated */         BodyLongTrailingIdx++;
/* Generated */    } while( i <= endIdx );
/* Generated */ #endif
/* Generated */    VALUE_HANDLE_DEREF(outNBElement) = outIdx;
/* Generated */    VALUE_HANDLE_DEREF(outBegIdx)    = startIdx;
/* Generated */    return ENUM_VALUE(RetCode,TA_SUCCESS,Success);
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }}} // Close namespace TicTacTec.TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/

