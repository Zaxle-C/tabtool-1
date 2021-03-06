﻿//THIS FILE IS GENERATED BY tabtool, DO NOT EDIT IT!
//GENERATE TIME [2018/1/19 15:42:21]

using System.Collections;
using System.Collections.Generic;
using System.Data;

namespace game_data {
public class td_test_item {
	public int role_id;
	public int cost_type;
	public int attack_type;
	public long head_id;
	public tbsIdCount test1;
	public List<tbsKeyValue> test2;
	public tbsTest test3;
	public List<td_head_item> __relate__td_head_items = new List<td_head_item>();
};

public class td_test : TableManager<td_test_item, td_test> {
	public override bool Load() {
		TableReader tr = new TableReader();
		DataReader dr = new DataReader();
		DataTable dt = tr.ReadFile(MyConfig.WorkDir+"test.txt");
		foreach(DataRow row in dt.Rows) {
			var item = new td_test_item();
			item.role_id = dr.GetValue<int>(row["role_id"].ToString());
			item.cost_type = dr.GetValue<int>(row["cost_type"].ToString());
			item.attack_type = dr.GetValue<int>(row["attack_type"].ToString());
			item.head_id = dr.GetValue<long>(row["head_id"].ToString());
			item.test1 = dr.GetObject<tbsIdCount>(row["test1"].ToString());
			item.test2 = dr.GetObjectList<tbsKeyValue>(row["test2"].ToString());
			item.test3 = dr.GetObject<tbsTest>(row["test3"].ToString());
			m_Items[item.role_id] = item;
		}
		return true;
	}
}
}

