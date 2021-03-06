﻿//THIS FILE IS GENERATED BY tabtool, DO NOT EDIT IT!
//GENERATE TIME [2018/1/19 15:42:21]
#pragma once
# include "readtablefield.h"
# include "tablestruct.h"

namespace game_data {

struct td_color_item;
struct td_head_item {
  int32_t head_id;
  int32_t head_type;
  int32_t test_type;
  std::vector<const td_color_item*> __relate__td_color_items;
};

class td_head : public IConfigTable<td_head_item>{
public:
virtual bool Load() {
	ReadTableFile reader;
	reader.Initialize();

	if (!reader.Init(GetTableFile().c_str()))
		return false;

	try {
		DataReader dr;
		int iRows = reader.GetRowCount();
		int iCols = reader.GetColCount();
		for (int i = 1; i < iRows; ++i) {
			td_head_item item;
			item.head_id = dr.GetValue<int32_t>(reader.GetValue(i, "head_id"));
			item.head_type = dr.GetValue<int32_t>(reader.GetValue(i, "head_type"));
			item.test_type = dr.GetValue<int32_t>(reader.GetValue(i, "test_type"));
			m_Items[item.head_id] = item;
		}
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
		return false;
	}
	return true;
}

string GetTableFile() {
	string f = WORK_DIR;
	f = f + "Head.txt";
	return f;
}

};

}
