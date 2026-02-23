#include "HashTable.h"
#include <iostream>


//해시 함수
//키를 어떠한 과정을 통해 숫자로 변환해주는 함수.
//여기에 붙이는 static은 전역이 아니라 private의 의미
static int GenerateKey(const std::string& keyString)
{
    // 출력할 해시 변수 선언.
    int hash = 0;


    //문자열을 문자 배열로 활용해 해시 생성.
    const int length = static_cast<int>(keyString.length());
    for (int i = 0; i < length; ++i)
    {
        //해시 생성 로직.
        //hash += keyString[i] * (i + 1);   //성능이 좋지는 않음
        hash = hash * 31 + keyString[i];  //java의 방식. hornor' method
    }

    return std::abs(hash);
}

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

bool HashTable::Add(const std::string& key, const std::string& value)
{
    //해시 값을 생성한 후에 이를 버킷 인덱스로 변환.
    int bucketIndex = GenerateKey(key) % bucketCount;

    //저장할 동적 배열 선택.
    std::vector<Entry>& position = table[bucketIndex];

    //중복된 키가 있는지 확인 후 없으면 추가.
    const int length = static_cast<int>(position.size());
    for (int i = 0; i < length; ++i)
    {
        if (position[i].key == key)
        {
            return false;
        }
    }

    position.emplace_back(Entry(key, value));
    return true;
}

bool HashTable::Delete(const std::string& key)
{
    //해시 값을 생성한 후에 이를 버킷 인덱스로 변환.
    int bucketIndex = GenerateKey(key) % bucketCount;

    //저장할 동적 배열 선택.
    std::vector<Entry>& position = table[bucketIndex];

    //중복된 키가 있는지 확인 후 있으면 삭제.
    const int length = static_cast<int>(position.size());
    for (int i = 0; i < length; ++i)
    {
        if (position[i].key == key)
        {
            //해당 키를 갖는 데이터를 2차 자료구조에서 제거.
            position.erase(position.begin() + i);
            return true;
        }
    }

    //position.emplace_back(Entry(key, value));
    return false;
}

bool HashTable::Find(const std::string& key, Entry& outEntry)
{

    //해시 값을 생성한 후에 이를 버킷 인덱스로 변환.
    int bucketIndex = GenerateKey(key) % bucketCount;

    //저장할 동적 배열 선택.
    std::vector<Entry>& position = table[bucketIndex];

    //중복된 키가 있는지 확인 후 있으면 삭제.
    const int length = static_cast<int>(position.size());
    for (int i = 0; i < length; ++i)
    {
        if (position[i].key == key)
        {
            outEntry = position[i];
            return true;
        }
    }

    //position.emplace_back(Entry(key, value));
    return false;
}

HashTable::Entry& HashTable::operator[](const std::string& key)
{
    //해시 값을 생성한 후에 이를 버킷 인덱스로 변환.
    int bucketIndex = GenerateKey(key) % bucketCount;

    //저장할 동적 배열 선택.
    std::vector<Entry>& position = table[bucketIndex];

    // 1. 기존 키 탐색
    for (Entry& entry : position)
    {
        if (entry.key == key)
            return entry;
    }

    // 2. 없으면 새로 생성 (value는 기본값 "")
    position.emplace_back(key, std::string());
    return position.back();
}


void HashTable::Print() 
{
    //모든 자료를 출력.
    for (const auto& container : table)
    {
        //2차 자료구조에 저장된 데이터 없으면 건너뛰기.
        if (container.size() == 0)
        {
            continue;
        }

       
        //데이터가 있으면 출력.
        for (const auto& item : container)
        {
            std::cout
                << "Key: " << item.key
                << " | Value: " << item.value
                << "\n";
        }
    }
}

//getter
bool HashTable::IsEmpty() const
{
    int sum = 0;
    for (const auto& container : table)
    {
        //2차 자료 구조의 저장된 데이터 수를 합산.
        sum += static_cast<int>(container.size());
    }

    return sum == 0;
}
