/*
 * static_model.c
 *
 * automatically generated from model.icd
 */
#include "static_model.h"

static void initializeValues();



LogicalDevice iedModel_VaconFreqConverter = {
    LogicalDeviceModelType,
    "VaconFreqConverter",
    (ModelNode*) &iedModel,
    NULL,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0
};

LogicalNode iedModel_VaconFreqConverter_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &iedModel_VaconFreqConverter,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Mod,
};

DataObject iedModel_VaconFreqConverter_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Beh,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Mod_q,
    0
};

DataAttribute iedModel_VaconFreqConverter_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Mod,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Mod_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Mod,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Mod_ctlModel,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Mod,
    NULL,
    NULL,
    0,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_VaconFreqConverter_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Health,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Beh_stVal,
    0
};

DataAttribute iedModel_VaconFreqConverter_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Beh,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Beh_q,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Beh,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Beh_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Beh,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_VaconFreqConverter_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_NamPlt,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Health_stVal,
    0
};

DataAttribute iedModel_VaconFreqConverter_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Health,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Health_q,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Health,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Health_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_Health,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_VaconFreqConverter_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0,
    NULL,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_NamPlt_vendor,
    0
};

DataAttribute iedModel_VaconFreqConverter_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_NamPlt,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_NamPlt_swRev,
    NULL,
    0,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_NamPlt,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_NamPlt_d,
    NULL,
    0,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_NamPlt,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_NamPlt_configRev,
    NULL,
    0,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_NamPlt,
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_NamPlt_ldNs,
    NULL,
    0,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &iedModel_VaconFreqConverter_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_VaconFreqConverter_DSFC1 = {
    LogicalNodeModelType,
    "DSFC1",
    (ModelNode*) &iedModel_VaconFreqConverter,
    NULL,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn0,
};

DataObject iedModel_VaconFreqConverter_DSFC1_AnIn0 = {
    DataObjectModelType,
    "AnIn0",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn1,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn0_mag,
    0
};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn0_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn0,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn0_q,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn0_mag_f,
    0,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn0_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn0_mag,
    NULL,
    NULL,
    0,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn0_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn0,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn0_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn0_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn0,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_VaconFreqConverter_DSFC1_AnIn1 = {
    DataObjectModelType,
    "AnIn1",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn2,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn1_mag,
    0
};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn1_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn1,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn1_q,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn1_mag_f,
    0,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn1_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn1_mag,
    NULL,
    NULL,
    0,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn1,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn1_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn1,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_VaconFreqConverter_DSFC1_AnIn2 = {
    DataObjectModelType,
    "AnIn2",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn3,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn2_mag,
    0
};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn2_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn2,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn2_q,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn2_mag_f,
    0,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn2_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn2_mag,
    NULL,
    NULL,
    0,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn2,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn2_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn2,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_VaconFreqConverter_DSFC1_AnIn3 = {
    DataObjectModelType,
    "AnIn3",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn4,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn3_mag,
    0
};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn3_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn3,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn3_q,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn3_mag_f,
    0,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn3_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn3_mag,
    NULL,
    NULL,
    0,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn3,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn3_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn3,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_VaconFreqConverter_DSFC1_AnIn4 = {
    DataObjectModelType,
    "AnIn4",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn5,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn4_mag,
    0
};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn4_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn4,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn4_q,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn4_mag_f,
    0,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn4_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn4_mag,
    NULL,
    NULL,
    0,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn4,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn4_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn4,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_VaconFreqConverter_DSFC1_AnIn5 = {
    DataObjectModelType,
    "AnIn5",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn6,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn5_mag,
    0
};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn5_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn5,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn5_q,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn5_mag_f,
    0,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn5_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn5_mag,
    NULL,
    NULL,
    0,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn5_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn5,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn5_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn5_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn5,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_VaconFreqConverter_DSFC1_AnIn6 = {
    DataObjectModelType,
    "AnIn6",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn7,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn6_mag,
    0
};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn6_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn6,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn6_q,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn6_mag_f,
    0,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn6_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn6_mag,
    NULL,
    NULL,
    0,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn6_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn6,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn6_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn6_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn6,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_VaconFreqConverter_DSFC1_AnIn7 = {
    DataObjectModelType,
    "AnIn7",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn8,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn7_mag,
    0
};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn7_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn7,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn7_q,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn7_mag_f,
    0,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn7_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn7_mag,
    NULL,
    NULL,
    0,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn7_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn7,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn7_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn7_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn7,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_VaconFreqConverter_DSFC1_AnIn8 = {
    DataObjectModelType,
    "AnIn8",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn9,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn8_mag,
    0
};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn8_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn8,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn8_q,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn8_mag_f,
    0,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn8_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn8_mag,
    NULL,
    NULL,
    0,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn8_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn8,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn8_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn8_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn8,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_VaconFreqConverter_DSFC1_AnIn9 = {
    DataObjectModelType,
    "AnIn9",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1,
    NULL,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn9_mag,
    0
};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn9_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn9,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn9_q,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn9_mag_f,
    0,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn9_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn9_mag,
    NULL,
    NULL,
    0,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn9_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn9,
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn9_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_VaconFreqConverter_DSFC1_AnIn9_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_VaconFreqConverter_DSFC1_AnIn9,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};







IedModel iedModel = {
    "SampleIED",
    &iedModel_VaconFreqConverter,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    initializeValues
};

static void
initializeValues()
{

iedModel_VaconFreqConverter_LLN0_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(0);
}
