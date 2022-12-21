//
//  main.c
//  infestPath
//
//  Created by Juyeop Kim on 2022/10/20.
//

#include <stdio.h>
#include <string.h>
#include "ifct_element.h"
#include "ifct_database.h"

#define MENU_PATIENT        1
#define MENU_PLACE          2
#define MENU_AGE            3
#define MENU_TRACK          4
#define MENU_EXIT           0

#define TIME_HIDE           2


int trackInfester(int patient_no, int *detected_time, int *place);
int main(int argc, const char * argv[]) {
    
    int menu_selection;
    void *ifct_element;
    FILE* fp;
    int pIndex, age, time;   //pIndex,age,time : sample.txt에 저장되어 있는 환자 index,나이,감염 날짜 
    int placeHist[N_HISTORY]; //환자의 최근 이동장소 
    int i;                  //파일에서 이동장소 저장하는 for문에서 사용하는 변수 
    int min_age,max_age;   //메뉴3에서 받을 최소 나이, 최대 나이 
    int Place;             
    char place_Name;			//메뉴 2에서 scanf로 입력받을 장소 
    int j=0,k=0;				//메뉴 3에서 for문 돌릴 때 사용하는 변수 
    
    //------------- 1. loading patient info file ------------------------------
    //1-1. FILE pointer open
    if (argc != 2)
    {
        printf("[ERROR] syntax : infestPath (file path).");
        return -1;
    }
    
    fp = fopen(argv[1],"r"); //argv[1]이 뜻하는 것 : 입력한 파일 이름 patient info.txt   argv[0]이 뜻하는 것 : 실행파일 자체 
    if (fp == NULL) //Error handling code 
    {
        printf("[ERROR] Failed to open database file!! (%s)\n", argv[1]);
        return -1;
    }
    
    //1-2. loading each patient informations
    //ifctele_genElement()//여기에 값을 적절하게 하나씩 
   
    while(3==(fscanf(fp,"%d %d %d",&pIndex,&age,&time))){
    	for(i=0;i<5;i++){
    		fscanf(fp,"%d",&placeHist[i]);
		}
		ifct_element = ifctele_genElement(pIndex,age,time,placeHist);//여기에 fscanf로 저장받은 값 넣어라. 
		ifctdb_addTail(ifct_element); 

	} 
	
    
    //1-3. FILE pointer close
    fclose(fp);
    
    do {
        printf("\n=============== INFECTION PATH MANAGEMENT PROGRAM (No. of patients : %i) =============\n", ifctdb_len());
        printf("1. Print details about a patient.\n");                      //MENU_PATIENT
        printf("2. Print list of patients infected at a place.\n");        //MENU_PLACE
        printf("3. Print list of patients in a range of age.\n");          //MENU_AGE
        printf("4. Track the root of the infection\n");                     //MENU_TRACK
        printf("0. Exit.\n");                                               //MENU_EXIT
        printf("=============== ------------------------------------------------------- =============\n\n");
        
        printf("Select a menu :");
        scanf("%d", &menu_selection);
        fflush(stdin);
        
        switch(menu_selection)
        {
            case MENU_EXIT:
                printf("Exiting the program... Bye bye.\n");
                break;
                
            case MENU_PATIENT:
            	printf("Patient index:");
            	scanf("%d",&ifct_element);
            	ifctele_printElement(ifctdb_getData(ifct_element));
            	
                break;
                
            case MENU_PLACE:
                printf("Place Name :");
                scanf("%s",&place_Name);
				for(k=0;k<ifctdb_len();k++){
				
				}
                break;
					
            case MENU_AGE:
                printf("minimal age : ");
                scanf("%d",&min_age);
                printf("maximal age : ");
                scanf("%d",&max_age);
                int cnt=0;	//주어진 범위 안에 환자 몇 명인지 세어 주는 역할 
                
                for(j=0;j<ifctdb_len();j++){
                	if((min_age <= ifctele_getAge(ifctdb_getData(j))) && max_age>=ifctele_getAge(ifctdb_getData(j))){
                		ifctele_printElement(ifctdb_getData(j));
                		cnt++;
					}
				}
				printf("There are %d patients whose age is between %d and %d.\n",cnt,min_age,max_age);
				printf("\n");
                break;
                
            case MENU_TRACK:
                printf("Patient Index : ");
                break;
                
            default:
                printf("[ERROR Wrong menu selection! (%i), please choose between 0 ~ 4\n", menu_selection);
                break;
		}
    
    } while(menu_selection != 0);
    
    
    return 0;
}
