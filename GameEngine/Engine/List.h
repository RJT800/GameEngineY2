#pragma once
#include <forward_list>

namespace GameEngine
{
	template<typename T>
	class List
	{
	public:
		List<T>() {}

		void add(T item);
		void remove(T item);
		void clear();

		auto begin();
		auto end();

		bool isEmpty();

	private:
		std::forward_list<T> m_list;
	};

	template<typename T>
	inline void List<T>::add(T item)
	{
		m_list.push_front(item);
	}

	template<typename T>
	inline void List<T>::remove(T item)
	{
		m_list.remove(item);
	}

	template<typename T>
	inline void List<T>::clear()
	{
		m_list.clear();
	}

	template<typename T>
	inline auto List<T>::begin()
	{
		return m_list.begin();
	}

	template<typename T>
	inline auto List<T>::end()
	{
		return m_list.end();
	}

	template<typename T>
	inline bool List<T>::isEmpty()
	{
		return m_list.empty();
	}

}




//template<typename AnyType>
//class LinkedList
//{
//public:
//	LinkedList();
//	LinkedList(const LinkedList<AnyType>& other);
//	~LinkedList();
//
//	void destroy();
//
//	Iterator<AnyType> begin() const;
//	Iterator<AnyType> end()const;
//
//	//AnyType first()const;
//	//AnyType last()const;
//
//	bool contains(const AnyType value)const;
//
//	void pushFront(const AnyType& value);
//	void pushBack(const AnyType& value);
//
//	AnyType popFront();
//	AnyType popBack();
//
//	bool insert(const AnyType& value, int index);
//	bool remove(const AnyType& value);
//
//	void print() const;
//
//	void initilaize();
//
//	bool isEmpty()const;
//
//	bool getData(Iterator<AnyType>& iter, int index);
//
//	int getLength() const;
//
//	void operator = (const LinkedList<AnyType>& otherLinkedList);
//
//	//void sort();
//
//private:
//	Node <AnyType>* m_first;
//	Node <AnyType>* m_last;
//
//	int m_nodeCount;
//};