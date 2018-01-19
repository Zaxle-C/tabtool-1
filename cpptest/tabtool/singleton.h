#pragma once

//单例模式 内部局部变量 不用释放内存
template<typename T>
class Singleton
{
private:
	static Singleton<T> m_Instance;
	Singleton<T>();
public:
	static Singleton<T>& Instance(){
		return m_Instance;
	}
	T* get(){ return &m_obj; }
	T* operator->()
	{
		return &m_obj;
	}

protected:
	T m_obj;
};

template<typename T>
Singleton<T> Singleton<T>::m_Instance;

//template<typename T>
//class Singleton {
//private:
//	static T* m_pInstance;
//	Singleton() = delete;
//public:
//	static T* Instance() {
//		if (m_pInstance == nullptr)  //判断是否第一次调用  
//			m_pInstance = new T();
//		return m_pInstance;
//	}
//	static void destroy() {
//		if (m_pInstance) {
//			delete m_Instance;
//		}
//	}
//
//};
//
//template<typename T>
//T* Singleton<T>::m_pInstance = nullptr;