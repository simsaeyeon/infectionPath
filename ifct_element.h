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

void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY]); //각 환자의 정보 정리해주는 역할 (generate elements)
char* ifctele_getPlaceName(int placeIndex);    // placeIndex받으면 해당하는 장소 출력 
int ifctele_getHistPlaceIndex(void* obj, int index); // 
unsigned int ifctele_getinfestedTime(void* obj);
int ifctele_getAge(void* obj);   //3. 환자 정보 매개변수로 받으면 나이 출력 
void ifctele_printElement(void* obj); //1. 특정 환자에 대한 정보 출력
#endif /* ifct_element_h */

//15번 구조체 내용 저장하는거 
