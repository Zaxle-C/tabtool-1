#pragma once

#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "readtablefile.h"
#include <vector>
#include <assert.h>
using namespace std;

template<typename T, typename F>
T lexical_cast(const F& f) {
	std::stringstream ss;
	ss << f;
	if (!ss) {
		throw std::logic_error("type_cast invalid source type\n");
	}
	T t;
	ss >> t;
	if (!ss) {
		throw std::logic_error("type_cast invalid target type\n");
	}
	return t;
}

template<typename T>
class IConfigTable
{
public:
	IConfigTable() = default;
	virtual ~IConfigTable() = default;
	//���ر�Ľӿ�
	virtual bool Load() = 0;
	//����һ����¼
	const T* GetTableItem(int id) const {
		auto it = m_Items.find(id);
		if (m_Items.end() == it)
			return nullptr;
		return &it->second;
	}

	//�������м�¼
	template<typename eee>
	bool ExecAll(eee e) {
		auto it = m_Items.begin();
		for(;it!=m_Items.end();++it)
		{
			if(!e.exec(it->second))
				return false;
		}
		return true;
	}

	//�õ����ļ�¼ID
	const int MaxID() const {
		return m_Items.rbegin()->first;
	}

	//�õ���С�ļ�¼ID
	const int MinID() const {
		return m_Items.begin()->first;
	}

	//ֱ�ӻ��map ����ֵ����
	auto RawMap()->auto const& { 
		return m_Items; 
	}
	//�õ���Ŀ��
	int GetitemCount() const {
		return m_Items.size();
	}

protected:
	std::map<int ,T> m_Items;
};

//tbs�еĽṹ�嶼������̳�
template<typename T>
struct ITableObject {
	virtual bool FromString(string s) = 0;
};

//���ֶζ�ȡ
class DataReader {
public:
	vector<string> GetStringList(string s, char delim) {
		vector<string> ret;
		size_t p1 = 0;
		size_t p2 = 0;
		p2 = s.find_first_of(delim, p1);
		while (p2 != string::npos)
		{
			ret.push_back(s.substr(p1, p2 - p1));
			p1 = p2 + 1;
			p2 = s.find_first_of(delim, p1);
		}
		if (p1 < s.length())
		{
			ret.push_back(s.substr(p1));
		}
		return ret;
	}

	template<typename T>
	T GetValue(string s) {
		if (s.empty())
			return T();
		T t = lexical_cast<T>(s);
		return t;
	}

	template<typename T>
	vector<T> GetList(string s) {
		vector<string> vs = GetStringList(s, ',');
		vector<T> ret;
		for (auto ss : vs) {
			T v = lexical_cast<T>(ss);
			ret.push_back(v);
		}
		return ret;
	}

	template<typename T>
	T GetObject(string s) {
		T t;
		assert(t.FromString(s));
		return t;
	}

	template<typename T>
	vector<T> GetObjectList(string s) {
		vector<string> vs = GetStringList(s, '|');
		vector<T>ret;
		for (auto ss : vs) {
			ret.push_back(GetObject<T>(ss));
		}
		return ret;
	}
};




