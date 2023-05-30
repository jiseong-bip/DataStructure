//
//  main.cpp
//  hashTable
//
//  Created by 전지성 on 2023/05/29.
//

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

#include <thread>

//주제 : hashtable

//Q) map vs hash map(c++ 표준 unordered map)
//map은 기본적으로 Red-black tree로 구성 -> 이진트리로 구성


//hash_map (unorderd_map)
//-추가/탐색/삭제 O(1)

//메모리를 내주고 속도를 취한다

// 해쉬 테이블
void testTable()
{
    struct User
    {
        int userid = 0;
        string username;
    };
    
    vector<User> users;
    users.resize(1000);
    
    users[777] = User{ 777, "jiseong"};
    
    string name = users[777].username;
    cout <<  name << endl;
    
    //테이블
    //키를 알면, 데이터를 한번에 찾을 수 있다
    
    //문제의 상황
    //int32_max (3억 -)
    //메모리는 무한이 아님
}


//보안
//
void TestHash()
{
     struct User
    {
         int userid = 0;
         string username;
     };
    
    vector<User> users;
    users.resize(10000);
    
    const int userid = 123456789;
    int key = {userid%1000};//hash = 고유번호
    
    //유저 정보 세팅
    users[key] = User{ userid, "jiseong"};
    
    User& user = users[key];
    if (user.userid == userid){
        string name = user.username;
        cout <<  name << endl;
    }
    //충돌 -> key 값이 겹침
    //충돌이 발생한 자리를 대신해서 다른 빈자리를 찾아나서면 됨
    //- 선형 조사법
    //hash[key] + 1  -> hash[Key] + 2
    //  이차 조사법
    //hash[key] +1^2 -> hash[key] + 2^2
    //chaining
}

void TestHashTableChaining()
{
    struct User
    {
        int userid = 0;
        string username;
    };
    
    vector<vector<User>> users;
    users.resize(10000);
    
    const int userid = 123456789;
    int key = {userid%1000};//hash = 고유번호
    
    //유저 정보 세팅
    users[key].push_back(User{ userid, "jiseong"});
    users[789].push_back(User{ 789, "asdqw"});
    
    //123456789번 유저 이름은?
    vector<User>& bucket = users[key];
    for (User& user : bucket)
    {
        if(user.userid == userid)
        {
            string name = user.username;
            cout <<  name << endl;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //testTable();
    TestHashTableChaining();
}
