#pragma once

//˵��������ļ������������ĸ��Ի�����

#define ErrorLog printf				//����ȥ������־�࣬������־��printf����
#define WORK_DIR  "tabtool/config/";	//config����Ŀ¼

const int MAX_TABLE_ROWS = 8000;	//���������
const int MAX_LINE_LEN = 8000;		//ÿ����󳤶�

template<typename T> //��ȡ������ģ��
T const& GET_TABLE();