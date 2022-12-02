//
//  ifct_element.h
//  infection path
//
//  Created by Juyeop Kim on 2022/10/20.
//

#ifndef ifct_element_h
#define ifct_element_h

#define N_PLACE                     40
#define N_HISTORY                   5
#define MAX_PLACENAME               100

void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY]);
char* ifctele_getPlaceName(int placeIndex);    // OK 
int ifctele_getHistPlaceIndex(void* obj, int index); 
unsigned int ifctele_getinfestedTime(void* obj);
int ifctele_getAge(void* obj);   //main함수에 제공하기 위한 함수로 '문'의 역할을 함. 
void ifctele_printElement(void* obj); //1. 특정 환자에 대한 정보 출력 
#endif /* ifct_element_h */

//16,17,18 -> ifctle_get_age와 비슷한 방향으로 짜면 됌.

//15번 구조체 내용 저장하는거 
