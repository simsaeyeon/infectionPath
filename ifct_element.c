//
//  ifs_element.c
//  InfestPath
//
//  Created by Juyeop Kim on 2020/10/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ifct_element.h"

typedef enum place {
    Seoul,          //0
    Jeju,           //1
    Tokyo,          //2
    LosAngeles,     //3
    NewYork,        //4
    Texas,          //5
    Toronto,        //6
    Paris,          //7
    Nice,           //8
    Rome,           //9
    Milan,          //10
    London,         //11
    Manchester,     //12
    Basel,          //13
    Luzern,         //14
    Munich,         //15
    Frankfurt,      //16
    Berlin,         //17
    Barcelona,      //18
    Madrid,         //19
    Amsterdam,      //20
    Stockholm,      //21
    Oslo,           //22
    Hanoi,          //23
    Bangkok,        //24
    KualaLumpur,    //25
    Singapore,      //26
    Sydney,         //27
    SaoPaulo,       //28
    Cairo,          //29
    Beijing,        //30
    Nairobi,        //31
    Cancun,         //32
    BuenosAires,    //33
    Reykjavik,      //34
    Glasgow,        //35
    Warsow,         //36
    Istanbul,       //37
    Dubai,          //38
    CapeTown        //39
} place_t;

char countryName[N_PLACE+1][MAX_PLACENAME] =
{   "Seoul",
    "Jeju",
    "Tokyo",
    "LosAngeles",
    "NewYork",
    "Texas",
    "Toronto",
    "Paris",
    "Nice",
    "Rome",
    "Milan",
    "London",
    "Manchester",
    "Basel",
    "Luzern",
    "Munich",
    "Frankfurt",
    "Berlin",
    "Barcelona",
    "Madrid",
    "Amsterdam",
    "Stockholm",
    "Oslo",
    "Hanoi",
    "Bangkok",
    "KualaLumpur",
    "Singapore",
    "Sydney",
    "SaoPaulo",
    "Cairo",
    "Beijing",
    "Nairobi",
    "Cancun",
    "BuenosAires",
    "Reykjavik",
    "Glasgow",
    "Warsow",
    "Istanbul",
    "Dubai",
    "CapeTown",
    "Unrecognized"
};

typedef struct ifs_ele{
	//번호  --> 정수
	//나이	--> 정수
	//감염 시점 --> 정수   (일수(바이러스 창궐한 이후 몇일째))
	//감염 직전 이동경로 --> (enum) place_t배열 (N_HISTORY) 
		//얘네들 다저장해야함 
	int Index;
	int age;
	int inf_detected_time;
	char place_t[N_HISTORY];  //OK
 
} ifs_ele_t;

static ifs_ele_t ifsarray[20];     //나중에 배운 수업 토대로 바꿀 예정  main.c에서 못끌어오도록 하기 위해 static 사용 for incapsulation 
static int ifs_cnt; //몇 명의 환자가 들어있는지 확인하는 용도 

int ifctele_getAge(void* obj){
	ifs_ele_t *strPtr = (ifs_ele_t *)obj;
	
	return (strPtr->age);   
	//구조체 안에서 나이의 값을 뽑아주는 역할
	//void pointer로 struct 갖고 있다고 생각하면 됌.
	//obj는 데이터 덩어리지만, 이걸 ifs_ele_t로 보겠다. 
	
	//ifs_ele_t *strPtr = (ifs_ele_t *)obj;
	//return(ifs_ele_t.age); //return이 나이를 출력하게끔  pointer로 멤버에 접근하는 방법 배운거 사용하기/ 
} 

 
char* ifctele_getPlaceName(int placeIndex){
	
	return countryName[placeIndex];
}

void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY]){
	//fscanf가 갖고 있는 정보 여기에 넣어야함. 
	ifsarray[ifs_cnt].Index=index;
	ifsarray[ifs_cnt].age=age;
	ifsarray[ifs_cnt].inf_detected_time=detected_time;
	ifsarray[ifs_cnt].place_t[N_HISTORY]= history_place[N_HISTORY];
	
	ifs_cnt++;
	return (void*)&ifsarray[ifs_cnt];
}

void ifctele_printElement(void* obj){
		ifs_ele_t *strPtr = (ifs_ele_t *)obj;
		
		//print elements
}


