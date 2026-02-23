#pragma once
#include <iostream>

template<typename KeyType, typename ValueType>
class Pair
{
public:
	KeyType key;

	ValueType value;


	Pair()
		: key(), value()
	{

	}


	Pair(const KeyType& key,const ValueType& value)
		:key(key), value(value)
	{


	}


	//연산자 오버로딩
	bool operator==(const Pair<KeyType, ValueType>& other) const
	{
		//전제 조건 : key와 vlaue 각각 비교가 가능해야함.
		return key == other.key && value == other.value;

	}

	bool operator!=(const Pair<KeyType, ValueType>& other) const
	{
		//전제 조건 : key와 vlaue 각각 비교가 가능해야함.
		return !(*this == other);

	}



	bool operator>(const Pair<KeyType, ValueType>& other)
	{
		//전제 조건 : key와 vlaue 각각 비교가 가능해야함.
		return  key > other.key;

	}

	bool operator<(const Pair<KeyType, ValueType>& other)
	{
		//전제 조건 : key와 vlaue 각각 비교가 가능해야함.
		return  key < other.key;

	}



	bool operator>=(const Pair<KeyType, ValueType>& other)
	{
		//전제 조건 : key와 vlaue 각각 비교가 가능해야함.
		return  key >= other.key;

	}

	bool operator<=(const Pair<KeyType, ValueType>& other)
	{
		//전제 조건 : key와 vlaue 각각 비교가 가능해야함.
		return  key <= other.key;

	}



};



template<typename KeyType, typename ValueType>
std::ostream& operator<<(std::ostream& os, const Pair<KeyType, ValueType>& pair)
{
	os << "[" << pair.key << " : " << pair.value << "]\n";
	return os;
}