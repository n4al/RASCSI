//---------------------------------------------------------------------------
//
//	X68000 EMULATOR "XM6"
//
//	Copyright (C) 2001-2006 ＰＩ．(ytanaka@ipc-tokai.or.jp)
//	Copyright (C) 2014-2020 GIMONS
//
//	[ Logic to determine type of SBC being used]
//
//---------------------------------------------------------------------------

#pragma once
#include "os.h"
#include <string>
#include <map>

//===========================================================================
//
//	Single Board Computer Versions
//
//===========================================================================
class SBC_Version
{
public:
	// Type of Single Board Computer
	enum sbc_version_type : uint8_t {
		sbc_unknown = 0,
		sbc_raspberry_pi_1,
		sbc_raspberry_pi_2_3,
		sbc_raspberry_pi_4,
		sbc_bananapi_m2_berry,
		sbc_bananapi_m2_zero,
		sbc_bananapi_m3,
		sbc_bananapi_m4,
	};

	static void Init();
	
	static sbc_version_type GetSbcVersion();

	static bool IsRaspberryPi();
	static bool IsBananaPi();

	static const std::string* GetString();

	static DWORD GetPeripheralAddress();

private:
	static sbc_version_type m_sbc_version;

	static const std::string m_str_raspberry_pi_1;
	static const std::string m_str_raspberry_pi_2_3;
	static const std::string m_str_raspberry_pi_4;
	static const std::string m_str_bananapi_m2_berry;
	static const std::string m_str_bananapi_m2_zero;
	static const std::string m_str_bananapi_m3;
	static const std::string m_str_bananapi_m4;
	static const std::string m_str_unknown_sbc;

	static const std::map<std::string, sbc_version_type> m_device_model_map; 

	static const std::string m_device_tree_model_path;

	static DWORD GetDeviceTreeRanges(const char *filename, DWORD offset);

};
