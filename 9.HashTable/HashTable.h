#pragma once

#include <vector>
#include <string>

#include "Pair.h"

class HashTable
{
public:


	//장황한 타입을 Entry로 치환.
	using Entry = Pair<std::string, std::string>;


public:
	HashTable();
	~HashTable();

	//키 - 값 조합으로 저장할수 있도록.
	bool Add(const std::string& key, const std::string& value);


	//삭제 - 키 활용해 k-value 조합 데이터 삭제.
	bool Delete(const std::string& key);


	//검색 함수
	bool Find(const std::string& key, Entry& outEntry);

	Entry& operator[](const std::string& key);
	
	void Print();

	//getter
	bool IsEmpty() const;


private:
	//내부 저장소 크기
	//- 내부 저장소 크기는 소수(1과 자기자신으로만 나눠지는 수)를 선택하는게 해시 충돌방지에좋음
	//사용가능한 소수중에서 큰수를 사용.
	static const int bucketCount = 19;


	//이차 저장소(해시 충돌 해결 방법으로 체이닝)
	std::vector<Entry> table[bucketCount];
};
