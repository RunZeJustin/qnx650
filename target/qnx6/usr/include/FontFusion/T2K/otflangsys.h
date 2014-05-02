/*
 * otflangsys.h
 * $Header: /home/archive/Panorama/layout/otf/hdr/otflangsys.h,v 1.16 2008/03/28 12:06:05 ljoshi Exp $
 * Font Fusion Copyright (c) 1989-2004 all rights reserved by Bitstream Inc.
 * http://www.bitstream.com/
 * http://www.typesolutions.com/
 * Author: Lokesh
 *
 * This software is the property of Bitstream Inc. and it is furnished
 * under a license and may be used and copied only in accordance with the
 * terms of such license and with the inclusion of the above copyright notice.
 * This software or any other copies thereof may not be provided or otherwise
 * made available to any other person or entity except as allowed under license.
 * No title to and no ownership of the software or intellectual property
 * contained herein is hereby transferred. This information in this software
 * is subject to change without notice
 */

#ifndef __OTFLANGSYS_HEADER__
#define __OTFLANGSYS_HEADER__

#ifndef LLM_LLCONFIG_HEADER
#include "LLConfig.h"
#else
#include LLM_LLCONFIG_HEADER
#endif 
#include LLM_OTFSCRIPT_HEADER
#include LLM_LLMTYPES_HEADER

#if defined(ENABLE_LLE) && defined(ENABLE_OTF)

#ifdef __cplusplus
extern "C" {
#endif 
	

typedef enum
{


	OTF_LANGSYS_DEFAULT = 0,


	OTF_LANGSYS_AFAR,
	OTF_LANGSYS_AZERI_LATIN,
	OTF_LANGSYS_CRIMEANTATAR,
	OTF_LANGSYS_DANISH,
	OTF_LANGSYS_DUTCH,
	OTF_LANGSYS_ENGLISH,
	OTF_LANGSYS_FAROESE,
	OTF_LANGSYS_FINISH,
	OTF_LANGSYS_FLEMISH,
	OTF_LANGSYS_GERMAN,
	OTF_LANGSYS_ICELANDIC,
	OTF_LANGSYS_IRISH,
	OTF_LANGSYS_ITALIAN,
	OTF_LANGSYS_NORWEGIAN,
	OTF_LANGSYS_PORTUGUESE,
	OTF_LANGSYS_SPANISH,
	OTF_LANGSYS_SWEDISH,
	
	OTF_LANGSYS_AFRIKAANS,
	OTF_LANGSYS_BASQUE,
	OTF_LANGSYS_BRETON,
	OTF_LANGSYS_CATALAN,
	OTF_LANGSYS_CROATIAN,
	OTF_LANGSYS_CZECH,
	OTF_LANGSYS_ESPERANTO,
	OTF_LANGSYS_ESTONIAN,
	OTF_LANGSYS_FRENCH,
	OTF_LANGSYS_FRISIAN,
	OTF_LANGSYS_GREENLANDIC,
	OTF_LANGSYS_HUNGARIAN,
	OTF_LANGSYS_LANG_LATIN,
	OTF_LANGSYS_LATVIAN,
	OTF_LANGSYS_LITHUANIAN,
	OTF_LANGSYS_MALTESE,
	OTF_LANGSYS_MOLDAVIAN,
	OTF_LANGSYS_POLISH,
	OTF_LANGSYS_PROVENCAL,
	OTF_LANGSYS_RHAETO_ROMANTIC,
	OTF_LANGSYS_ROMANIAN,
	OTF_LANGSYS_ROMANY,
	OTF_LANGSYS_SLOVAK,
	OTF_LANGSYS_SLOVENIAN,
	OTF_LANGSYS_SORBIAN_LOWER,
	OTF_LANGSYS_SORBIAN_UPPER,
	OTF_LANGSYS_TURKISH,
	OTF_LANGSYS_WELSH,
	OTF_LANGSYS_VIETNAMESE,
	
	
	OTF_LANGSYS_AZERI_CYRILLIC,
	OTF_LANGSYS_RUSSIAN,
	OTF_LANGSYS_SERBIAN,
	
	
	OTF_LANGSYS_COPTIC,
	OTF_LANGSYS_GREEK,
	
	
	OTF_LANGSYS_ARMENIAN,
	
	
	OTF_LANGSYS_GEORGIAN,
	
	OTF_LANGSYS_RUNIC,
	OTF_LANGSYS_OGHAM,


	OTF_LANGSYS_ARABIC,
	OTF_LANGSYS_AZERI_ARABIC,
	OTF_LANGSYS_BALOCHI,
	OTF_LANGSYS_BALTI,
	OTF_LANGSYS_BERBER,
	OTF_LANGSYS_BRAHUI,
	OTF_LANGSYS_DOGRI,
	OTF_LANGSYS_FARSI,
	OTF_LANGSYS_FULANI,
	OTF_LANGSYS_HAUSA,
	OTF_LANGSYS_HINDKO,
	OTF_LANGSYS_KANURI,
	OTF_LANGSYS_ARA_KASHMIRI, 
	OTF_LANGSYS_KHOWAR,
	OTF_LANGSYS_KIRGHIZ,
	OTF_LANGSYS_KURDISH,
	OTF_LANGSYS_LADAKHI,
	OTF_LANGSYS_MALAY,
	OTF_LANGSYS_MANDINKA,
	OTF_LANGSYS_PASHTO,
	OTF_LANGSYS_PUNJABI,
	OTF_LANGSYS_SARAIKI,
	OTF_LANGSYS_ARA_SINDHI, 
	OTF_LANGSYS_SOMALI,
	OTF_LANGSYS_SWAHILI,
	OTF_LANGSYS_URDU,
	OTF_LANGSYS_UYGHUR,

	
	
	OTF_LANGSYS_ASSAMESE,
	OTF_LANGSYS_BENGALI,
	OTF_LANGSYS_GARO,
	OTF_LANGSYS_KHASI,
	OTF_LANGSYS_MANIPURI,
	OTF_LANGSYS_MUNDARI_BENGALI,
	OTF_LANGSYS_RIANG,
	OTF_LANGSYS_SANTALI_BENGALI,
	
	
	OTF_LANGSYS_AWADHI,
	OTF_LANGSYS_BHILI,
	OTF_LANGSYS_BHOJPURI,
	OTF_LANGSYS_BRAJ,
	OTF_LANGSYS_GARHWALI,
	OTF_LANGSYS_GONDI_DEVANAGARI,
	OTF_LANGSYS_HINDI,
	OTF_LANGSYS_HO,
	OTF_LANGSYS_HARAUTI,
	OTF_LANGSYS_KACHCHI,
	OTF_LANGSYS_KASHMIRI,
	OTF_LANGSYS_KONKANI,
	OTF_LANGSYS_KURUKH,
	OTF_LANGSYS_LIMBU,
	OTF_LANGSYS_MAITHILI,
	OTF_LANGSYS_MARATHI,
	OTF_LANGSYS_MARWARI,
	OTF_LANGSYS_MUNDARI_DEVANAGARI,
	OTF_LANGSYS_NEPALI,
	OTF_LANGSYS_NEWARI,
	OTF_LANGSYS_SANSKRIT,
	OTF_LANGSYS_SANTALI_DEVANAGARI,
	OTF_LANGSYS_SINDHI,
	
	
	OTF_LANGSYS_GUJARATI,
	
	
	OTF_LANGSYS_GURMUKHI,
	
	
	OTF_LANGSYS_KANNADA,
	OTF_LANGSYS_TULU,
	
	
	OTF_LANGSYS_MALAYALAM_OLD,
	OTF_LANGSYS_MALAYALAM_NEW,
	
	
	OTF_LANGSYS_ORIYA,
	OTF_LANGSYS_SANTALI_ORIYA,
	
	
	OTF_LANGSYS_BADAGA,
	OTF_LANGSYS_TAMIL,
	
	
	OTF_LANGSYS_GONDI_TELUGU,
	OTF_LANGSYS_TELUGU,


	OTF_LANGSYS_HEBREW,
	OTF_LANGSYS_JUDEZMO,
	OTF_LANGSYS_YIDDISH,


	OTF_LANGSYS_KOREAN,


	OTF_LANGSYS_KUY,
	OTF_LANGSYS_PALI,
	OTF_LANGSYS_THAI_SANSKRIT,
	OTF_LANGSYS_THAI,

	
	OTF_LANGSYS_DIVEHI,

	
	OTF_LANGSYS_LAO,

	
	OTF_LANGSYS_SYRIAC,

	
	OTF_LANGSYS_KHMER,

	
	OTF_MAX_LANGSYS

}LLMLangName;



typedef struct {

	uint32 tag;
#ifdef ENABLE_OTFTAGS_STRINGS
	char * name;
#endif 
	LLMLangName id;

} OTFLangsysTag;



typedef struct {
	const OTFLangsysTag *tagArray;
	uint32    arraySize;
	LLMScriptName script;
	LLMLangName firstID;
	LLMLangName lastID;
}OTFLangSysHead;


typedef struct 
{
	uint16 initialUni;
	uint16 finalUni;
	uint32 tag;
}UniRangeScript;



const OTFLangsysTag *
getLangFromTag(uint32 tag, LLMScriptName scriptID);

const OTFLangSysHead * getLangSysHeadFromID(LLMScriptName scriptEnum);


const OTFScriptTag * getScriptfromLang(LLMLangName langEnum);


const OTFLangsysTag * 
getLangFromID(LLMScriptName scriptID, LLMLangName langID);


uint8 LLM_isLangValid( LLMLangName langID, LLMScriptName scriptID);

uint16 getScriptType(LLMUnicode unicode);

#ifdef __cplusplus
}
#endif 
	
#endif 

#endif 



