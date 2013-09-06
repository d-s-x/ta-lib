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
 *  MF       Mario Fortier
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  120802 MF   Template creation.
 *  052603 MF   Adapt code to compile with .NET Managed C++
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
/* Generated */ int Core::AdOscLookback( int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                        int           optInSlowPeriod )  /* From 2 to 100000 */
/* Generated */ 
/* Generated */ #elif defined( _JAVA )
/* Generated */ public int adOscLookback( int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                         int           optInSlowPeriod )  /* From 2 to 100000 */
/* Generated */ 
/* Generated */ #else
/* Generated */ TA_LIB_API int TA_ADOSC_Lookback( int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                                            int           optInSlowPeriod )  /* From 2 to 100000 */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert local variable here */
   int slowestPeriod;

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */    /* min/max are checked for optInFastPeriod. */
/* Generated */    if( (int)optInFastPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInFastPeriod = 3;
/* Generated */    else if( ((int)optInFastPeriod < 2) || ((int)optInFastPeriod > 100000) )
/* Generated */       return -1;
/* Generated */ 
/* Generated */    /* min/max are checked for optInSlowPeriod. */
/* Generated */    if( (int)optInSlowPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInSlowPeriod = 10;
/* Generated */    else if( ((int)optInSlowPeriod < 2) || ((int)optInSlowPeriod > 100000) )
/* Generated */       return -1;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/

   /* insert lookback code here. */

   /* Use the slowest EMA period to evaluate the total lookback. */
   if( optInFastPeriod < optInSlowPeriod )
      slowestPeriod = optInSlowPeriod;
   else
      slowestPeriod = optInFastPeriod;

   /* Adjust startIdx to account for the lookback period. */
   return LOOKBACK_CALL(EMA)( slowestPeriod );
}

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/*
 * TA_ADOSC - Chaikin A/D Oscillator
 * 
 * Input  = High, Low, Close, Volume
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInFastPeriod:(From 2 to 100000)
 *    Number of period for the fast MA
 * 
 * optInSlowPeriod:(From 2 to 100000)
 *    Number of period for the slow MA
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED ) && defined( USE_SUBARRAY )
/* Generated */ enum class Core::RetCode Core::AdOsc( int    startIdx,
/* Generated */                                       int    endIdx,
/* Generated */                                       SubArray<double>^ inHigh,
/* Generated */                                       SubArray<double>^ inLow,
/* Generated */                                       SubArray<double>^ inClose,
/* Generated */                                       SubArray<double>^ inVolume,
/* Generated */                                       int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                                       int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                                       [Out]int%    outBegIdx,
/* Generated */                                       [Out]int%    outNBElement,
/* Generated */                                       SubArray<double>^  outReal )
/* Generated */ #elif defined( _MANAGED )
/* Generated */ enum class Core::RetCode Core::AdOsc( int    startIdx,
/* Generated */                                       int    endIdx,
/* Generated */                                       cli::array<double>^ inHigh,
/* Generated */                                       cli::array<double>^ inLow,
/* Generated */                                       cli::array<double>^ inClose,
/* Generated */                                       cli::array<double>^ inVolume,
/* Generated */                                       int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                                       int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                                       [Out]int%    outBegIdx,
/* Generated */                                       [Out]int%    outNBElement,
/* Generated */                                       cli::array<double>^  outReal )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public RetCode adOsc( int    startIdx,
/* Generated */                       int    endIdx,
/* Generated */                       double       inHigh[],
/* Generated */                       double       inLow[],
/* Generated */                       double       inClose[],
/* Generated */                       double       inVolume[],
/* Generated */                       int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                       int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                       MInteger     outBegIdx,
/* Generated */                       MInteger     outNBElement,
/* Generated */                       double        outReal[] )
/* Generated */ #else
/* Generated */ TA_LIB_API TA_RetCode TA_ADOSC( int    startIdx,
/* Generated */                                 int    endIdx,
/* Generated */                                            const double inHigh[],
/* Generated */                                            const double inLow[],
/* Generated */                                            const double inClose[],
/* Generated */                                            const double inVolume[],
/* Generated */                                            int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                                            int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                                            int          *outBegIdx,
/* Generated */                                            int          *outNBElement,
/* Generated */                                            double        outReal[] )
/* Generated */ #endif
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
{
	/* insert local variable here */

   int today, outIdx, lookbackTotal;
   int slowestPeriod;
   double high, low, close, tmp;

   double slowEMA, slowk, one_minus_slowk;
   double fastEMA, fastk, one_minus_fastk;
   double ad;

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
/* Generated */    if(!inHigh||!inLow||!inClose||!inVolume)
/* Generated */       return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */ 
/* Generated */    #endif /* !defined(_JAVA)*/
/* Generated */    /* min/max are checked for optInFastPeriod. */
/* Generated */    if( (int)optInFastPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInFastPeriod = 3;
/* Generated */    else if( ((int)optInFastPeriod < 2) || ((int)optInFastPeriod > 100000) )
/* Generated */       return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */ 
/* Generated */    /* min/max are checked for optInSlowPeriod. */
/* Generated */    if( (int)optInSlowPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInSlowPeriod = 10;
/* Generated */    else if( ((int)optInSlowPeriod < 2) || ((int)optInSlowPeriod > 100000) )
/* Generated */       return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */ 
/* Generated */    #if !defined(_JAVA)
/* Generated */    if( !outReal )
/* Generated */       return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */ 
/* Generated */    #endif /* !defined(_JAVA) */
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* Implementation Note:
    *     The fastEMA varaible is not neceseraly the
    *     fastest EMA.
    *     In the same way, slowEMA is not neceseraly the
    *     slowest EMA.
    *
    *     The ADOSC is always the (fastEMA - slowEMA) regardless
    *     of the period specified. In other word:
    * 
    *     ADOSC(3,10) = EMA(3,AD) - EMA(10,AD)
    *
    *        while
    *
    *     ADOSC(10,3) = EMA(10,AD)- EMA(3,AD)
    *
    *     In the first case the EMA(3) is truly a faster EMA,
    *     while in the second case, the EMA(10) is still call
    *     fastEMA in the algorithm, even if it is in fact slower.
    *
    *     This gives more flexibility to the user if they want to
    *     experiment with unusual parameter settings.
    */

   /* Identify the slowest period. 
    * This infomration is used soleley to bootstrap
    * the algorithm (skip the lookback period).
    */
   if( optInFastPeriod < optInSlowPeriod )
      slowestPeriod = optInSlowPeriod;
   else
      slowestPeriod = optInFastPeriod;

   /* Adjust startIdx to account for the lookback period. */
   lookbackTotal = LOOKBACK_CALL(EMA)( slowestPeriod );
   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNBElement);
      return ENUM_VALUE(RetCode,TA_SUCCESS,Success);
   }

   VALUE_HANDLE_DEREF(outBegIdx) = startIdx;
   today  = startIdx-lookbackTotal;

   /* The following variables and macro are used to
    * calculate the "ad".
    */
   ad = 0.0;
   #define CALCULATE_AD \
   { \
      high  = inHigh[today]; \
      low   = inLow[today]; \
      tmp   = high-low; \
      close = inClose[today]; \
      if( tmp > 0.0 ) \
         ad += (((close-low)-(high-close))/tmp)*((double)inVolume[today]); \
      today++; \
   }

   /* Constants for EMA */
   fastk = PER_TO_K( optInFastPeriod );
   one_minus_fastk = 1.0 - fastk;

   slowk = PER_TO_K( optInSlowPeriod );
   one_minus_slowk = 1.0 - slowk;

   /* Initialize the two EMA
    *
    * Use the same range of initialization inputs for
    * both EMA and simply seed with the first A/D value.
    *
    * Note: Metastock do the same.
    */   
   CALCULATE_AD;
   fastEMA = ad;
   slowEMA = ad;

   /* Initialize the EMA and skip the unstable period. */
   while( today < startIdx )
   {
      CALCULATE_AD;
      fastEMA = (fastk*ad)+(one_minus_fastk*fastEMA);
      slowEMA = (slowk*ad)+(one_minus_slowk*slowEMA);
   }     
      
   /* Perform the calculation for the requested range */
   outIdx = 0;
   while( today <= endIdx )
   {
      CALCULATE_AD;
      fastEMA = (fastk*ad)+(one_minus_fastk*fastEMA);
      slowEMA = (slowk*ad)+(one_minus_slowk*slowEMA);

      outReal[outIdx++] = fastEMA - slowEMA;
   }
   VALUE_HANDLE_DEREF(outNBElement) = outIdx;

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
/* Generated */ enum class Core::RetCode Core::AdOsc( int    startIdx,
/* Generated */                                       int    endIdx,
/* Generated */                                       SubArray<float>^ inHigh,
/* Generated */                                       SubArray<float>^ inLow,
/* Generated */                                       SubArray<float>^ inClose,
/* Generated */                                       SubArray<float>^ inVolume,
/* Generated */                                       int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                                       int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                                       [Out]int%    outBegIdx,
/* Generated */                                       [Out]int%    outNBElement,
/* Generated */                                       SubArray<double>^  outReal )
/* Generated */ #elif defined( _MANAGED )
/* Generated */ enum class Core::RetCode Core::AdOsc( int    startIdx,
/* Generated */                                       int    endIdx,
/* Generated */                                       cli::array<float>^ inHigh,
/* Generated */                                       cli::array<float>^ inLow,
/* Generated */                                       cli::array<float>^ inClose,
/* Generated */                                       cli::array<float>^ inVolume,
/* Generated */                                       int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                                       int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                                       [Out]int%    outBegIdx,
/* Generated */                                       [Out]int%    outNBElement,
/* Generated */                                       cli::array<double>^  outReal )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public RetCode adOsc( int    startIdx,
/* Generated */                       int    endIdx,
/* Generated */                       float        inHigh[],
/* Generated */                       float        inLow[],
/* Generated */                       float        inClose[],
/* Generated */                       float        inVolume[],
/* Generated */                       int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                       int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                       MInteger     outBegIdx,
/* Generated */                       MInteger     outNBElement,
/* Generated */                       double        outReal[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_ADOSC( int    startIdx,
/* Generated */                        int    endIdx,
/* Generated */                        const float  inHigh[],
/* Generated */                        const float  inLow[],
/* Generated */                        const float  inClose[],
/* Generated */                        const float  inVolume[],
/* Generated */                        int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                        int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                        int          *outBegIdx,
/* Generated */                        int          *outNBElement,
/* Generated */                        double        outReal[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    int today, outIdx, lookbackTotal;
/* Generated */    int slowestPeriod;
/* Generated */    double high, low, close, tmp;
/* Generated */    double slowEMA, slowk, one_minus_slowk;
/* Generated */    double fastEMA, fastk, one_minus_fastk;
/* Generated */    double ad;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return ENUM_VALUE(RetCode,TA_OUT_OF_RANGE_START_INDEX,OutOfRangeStartIndex);
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return ENUM_VALUE(RetCode,TA_OUT_OF_RANGE_END_INDEX,OutOfRangeEndIndex);
/* Generated */     #if !defined(_JAVA)
/* Generated */     if(!inHigh||!inLow||!inClose||!inVolume)
/* Generated */        return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */     #endif 
/* Generated */     if( (int)optInFastPeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInFastPeriod = 3;
/* Generated */     else if( ((int)optInFastPeriod < 2) || ((int)optInFastPeriod > 100000) )
/* Generated */        return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */     if( (int)optInSlowPeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInSlowPeriod = 10;
/* Generated */     else if( ((int)optInSlowPeriod < 2) || ((int)optInSlowPeriod > 100000) )
/* Generated */        return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */     #if !defined(_JAVA)
/* Generated */     if( !outReal )
/* Generated */        return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */     #endif 
/* Generated */  #endif 
/* Generated */    if( optInFastPeriod < optInSlowPeriod )
/* Generated */       slowestPeriod = optInSlowPeriod;
/* Generated */    else
/* Generated */       slowestPeriod = optInFastPeriod;
/* Generated */    lookbackTotal = LOOKBACK_CALL(EMA)( slowestPeriod );
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNBElement);
/* Generated */       return ENUM_VALUE(RetCode,TA_SUCCESS,Success);
/* Generated */    }
/* Generated */    VALUE_HANDLE_DEREF(outBegIdx) = startIdx;
/* Generated */    today  = startIdx-lookbackTotal;
/* Generated */    ad = 0.0;
/* Generated */    #define CALCULATE_AD \
/* Generated */    { \
/* Generated */       high  = inHigh[today]; \
/* Generated */       low   = inLow[today]; \
/* Generated */       tmp   = high-low; \
/* Generated */       close = inClose[today]; \
/* Generated */       if( tmp > 0.0 ) \
/* Generated */          ad += (((close-low)-(high-close))/tmp)*((double)inVolume[today]); \
/* Generated */       today++; \
/* Generated */    }
/* Generated */    fastk = PER_TO_K( optInFastPeriod );
/* Generated */    one_minus_fastk = 1.0 - fastk;
/* Generated */    slowk = PER_TO_K( optInSlowPeriod );
/* Generated */    one_minus_slowk = 1.0 - slowk;
/* Generated */    CALCULATE_AD;
/* Generated */    fastEMA = ad;
/* Generated */    slowEMA = ad;
/* Generated */    while( today < startIdx )
/* Generated */    {
/* Generated */       CALCULATE_AD;
/* Generated */       fastEMA = (fastk*ad)+(one_minus_fastk*fastEMA);
/* Generated */       slowEMA = (slowk*ad)+(one_minus_slowk*slowEMA);
/* Generated */    }     
/* Generated */    outIdx = 0;
/* Generated */    while( today <= endIdx )
/* Generated */    {
/* Generated */       CALCULATE_AD;
/* Generated */       fastEMA = (fastk*ad)+(one_minus_fastk*fastEMA);
/* Generated */       slowEMA = (slowk*ad)+(one_minus_slowk*slowEMA);
/* Generated */       outReal[outIdx++] = fastEMA - slowEMA;
/* Generated */    }
/* Generated */    VALUE_HANDLE_DEREF(outNBElement) = outIdx;
/* Generated */    return ENUM_VALUE(RetCode,TA_SUCCESS,Success);
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }}} // Close namespace TicTacTec.TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/

