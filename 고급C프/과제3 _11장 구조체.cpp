#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
//problem 1-2
////з儅 掘褻羹 摹樹
//typedef struct student {
//	//檜葷
//	char name[10];
//	//з廓
//	char id[11];
//	//撩瞳
//	char grade;
//}Student;
//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
//problem 2-2
//з儅 掘褻羹 摹樹
//typedef struct student {
//	//檜葷
//	char name[21];
//	//措橫 薄熱
//	int kor;
//	//艙橫 薄熱
//	int eng;
//	//熱з 薄熱
//	int math;
//	//ゎ敕
//	double avg;
//}Student;
////л熱 摹樹
//void read_data(Student* pSt, int n);
//void sort_score(Student* pSt, int n);
//Student* select_out(Student* p, Student* q, int n);
//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
//problem 3-2
////��蘿 掘褻羹 摹樹
//typedef struct hotel {
//	//檜葷, 蛔晝, ゎっ, 剪葬, 褻衝んл罹睡
//	char name[31];
//	int level;
//	double reputation;
//	double distance;
//	char includeBreakfast;
//}HOTEL;
////л熱 摹樹
//int in_hotel_info(HOTEL *p);
//void out_hotel_info(HOTEL *p, int N, int G, double D);
//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
//problem 4
//輿離 薑爾 掘褻羹 摹樹
//typedef struct parking_info {
//	//離 廓��, ア 廓��, 鼻ヶ 囀萄, 薑晦掏 爾嶸 罹睡(Y/N), 薑晦掏 謙盟, 輿離 衛除, 譆謙 綠辨
//	int carNum;
//	int phoneNum;
//	char product;
//	char isRegular;
//	int regularDay;
//	int parkingTime;
//	double cost = 0;
//}PARKING_INFO;
////л熱 摹樹
//void input(PARKING_INFO *p, int n);
//void compute(PARKING_INFO *p);
//void display(PARKING_INFO *p, int n);
//void parking_info_sort(PARKING_INFO *p, int n);
//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
//problem 5
//з儅 掘褻羹 摹樹
typedef struct stu {
	//檜葷, з廓, 婁跡曖 偃熱, 婁跡檜葷, 鏃菜з薄
	char name[31];
	int id;
	int gradeCnt;
	char grade[10][31];
	double point;
}Student;
//掘褻羹 寡翮 摹樹
Student students[100];
//з儅 熱蒂 氬擎 瞪羲滲熱 摹樹
int studentCnt = 0;
//殮溘 л熱
void inputStudent();
//薑溺 л熱
void sortStudent(Student arr[], int cnt);
//餉薯 л熱
void deleteStudent();
//轎溘 л熱
void printStudent(Student arr[], int cnt);
int main() {
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	//problem 1-2
	////掘褻羹 寡翮 摹樹
	//Student stus[5];
	////奩犒僥 牖�蛾� 滲熱
	//int i,j;
	////5貲曖 з儅縑 渠и 薑爾蒂 殮溘嫡嬴撿ж嘎煎 5廓 奩犒
	//for (i = 0; i < 5; i++) {
	//	//檜葷, з廓, 撩瞳 殮溘
	//	scanf("%s %s %c",&stus[i].name, &stus[i].id, &stus[i].grade);
	//	//幗ぷ縑 陴嬴氈朝 偃ч僥濠 薯剪
	//	getchar();
	//}
	////瓊堅濠 ж朝 з儅曖 檜葷, 斜 з儅曖 撩瞳, 斜 з儅曖 殮з喇紫
	//char findName[10], findGrade, findYear[5];
	////檜葷 殮溘
	//scanf("%s",&findName);
	//for (i = 0; i < 5; i++) {
	//	//虜擒 殮溘嫡擎 檜葷婁 偽擎 檜葷檣 з儅檜 掘褻羹 寡翮縑 襄營и棻賊
	//	if (strcmp(findName, stus[i].name)==0) {
	//		//斜 з儅曖 撩瞳婁 殮з喇紫縑 高擊 盪濰л.
	//		findGrade = stus[i].grade;
	//		strncpy(findYear,stus[i].id,4);
	//	}
	//}
	//findYear[4] = NULL;

	////褻勒縑 蜃朝 з儅檜 氈朝雖 橈朝雖 釭顫鳥 滲熱
	//int chk=0;
	//for (i = 0; i < 5; i++) {
	//	char strYear[5];
	//	strncpy(strYear, stus[i].id, 4);
	//	strYear[4]=NULL;
	//	//虜擒 殮溘嫡擎 з儅曖 撩瞳婁 偽擎 撩瞳擊 陛霞 з儅擊 瓊朝棻賊
	//	if (findGrade == stus[i].grade) {
	//		//殮溘嫡擎 з儅檜 嬴棲堅, 殮з喇紫陛 偽棻賊
	//		if ((strcmp(findName, stus[i].name) != 0) && (strcmp(strYear, findYear)==0)) {
	//			//chk高擊 夥脯輿堅 檜葷擊 轎溘п遽棻.
	//			chk=1;
	//			printf("%s ",stus[i].name);
	//		}
	//	}
	//}
	////虜擒 chk高檜 夥船雖 彊懊棻賊 0擊 轎溘
	//if(!chk)
	//	printf("0\n");
	//printf("\n");
	////瓊堅濠 ж朝 з儅曖 殮з喇紫諦 殮з喇紫蒂 131煎 釭換 釭該雖 轎溘
	//int num = atoi(findYear)%131;
	//printf("%s %d",findYear,num);
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	//problem 2-2
	////з儅 熱 殮溘
	//int n;
	//scanf("%d",&n);
	////掘褻羹 寡翮 舒 偃諦 陝陝曖 掘褻羹 ん檣攪 滲熱 舒偃, 譆謙 轎溘й ん檣攪 滲熱 摹樹
	//Student st1[49], st2[49], *pSt, *qSt, *finalSt;
	////pSt朝 st1蒂, qSt朝 st2蒂 陛葬酈啪 л
	//pSt = st1;
	//qSt = st2;
	////舒 偃曖 掘褻羹 殮溘嫡擠
	//read_data(pSt, n);
	//read_data(qSt, n);
	////舒 掘褻羹 薑溺
	//sort_score(pSt, n);
	//sort_score(qSt, n);
	////舒 掘褻羹 醞縑憮 褻勒縑 蜃朝 掘褻羹ん檣攪蒂 奩�納狤� finalSt縑 盪濰
	//finalSt = select_out(pSt, qSt, n);
	////finalSt蒂 牖�裔牉� 轎溘и棻.
	//for (Student* iter = finalSt; iter < finalSt + n; iter++) {
	//	printf("%s %d %d %d %.1f\n",iter->name, iter->kor, iter->eng, iter->math, iter->avg);
	//}
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	//problem 3-2
	////掘褻羹 寡翮婁 斜 寡翮擊 陛葬酈朝 ん檣攪 滲熱 摹樹
	//HOTEL hotels[100], *pHotel;
	//pHotel = hotels;
	////��蘿菟曖 薑爾蒂 殮溘嫡堅 殮溘嫡擎 偃熱蒂 奩�納狤� hotelCnt縑 盪濰.
	//int hotelCnt = in_hotel_info(pHotel);
	//int G;
	//double D;
	////G, D 殮溘嫡擠
	//scanf("%d %lf",&G,&D);
	////л熱碳楝諦憮 譆謙高 轎溘
	//out_hotel_info(pHotel, hotelCnt, G, D);
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	//problem 4
	////掘褻羹 寡翮 摹樹
	//PARKING_INFO parkingLot[100];
	////掘褻羹 寡翮擊 陛葬酈朝 ん檣攪 摹樹
	//PARKING_INFO *p=parkingLot;
	////離 偃熱 殮溘嫡擠
	//int n;
	//scanf("%d",&n);
	//getchar();
	////л熱 碳楝諦憮 掘褻羹 寡翮縑 高 盪濰
	//input(p, n);
	////寡翮擊 牖�裔牉� 陝 掘褻羹曖 輿離綠辨擊 啗骯л
	//for (p = parkingLot; p < parkingLot + n; p++) {
	//	compute(p);
	//}
	////ん檣攪 蟾晦��
	//p=parkingLot;
	////掘褻羹 寡翮 薑溺л熱 碳楝褥
	//parking_info_sort(p,n);
	////譆謙 高 轎溘
	//display(p,n);
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	//problem 5

	while (1) {
		//貲滄橫 殮溘嫡擠
		char code;
		scanf("%c",&code);
		//偃ч僥濠 薯剪
		getchar();
		//з儅薑爾 殮溘
		if (code == 'I') {
			inputStudent();
		}
		//з儅 檜葷牖戲煎 薑溺 �� 轎溘
		else if (code == 'S') {
			sortStudent(students, studentCnt);
		}
		//з儅薑爾 餉薯
		else if (code == 'D') {
			deleteStudent();
		}	
		//陴嬴氈朝 賅萇 з儅 薑爾 轎溘
		else if (code == 'P') {
			printStudent(students, studentCnt);
		}
		//Щ煎斜極 謙猿
		else if(code=='Q'){
			break;
		}
	}
	
}

//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天

////殮溘 л熱
//void read_data(Student* pSt, int n)
//{
//	//奩犒僥 牖�蛾�	掘褻羹 ん檣攪 滲熱
//	Student* iter;
//	for (iter = pSt; iter < pSt + n; iter++) {
//		//n廓 奩犒ж貊 殮溘嫡擠
//		scanf("%s %d %d %d",&iter->name, &iter->kor, &iter->eng, &iter->math);
//		getchar();
//		//ゎ敕高 蟾晦�倆媮�.
//		iter->avg = ((iter->kor) + (iter->eng) + (iter->math))/3.0;
//	}
//}
//
////薑溺 л熱
//void sort_score(Student* pSt, int n)
//{
//	//牖�蛾� 掘褻羹 ん檣攪 滲熱 舒偃 摹樹
//	Student* iter1, *iter2;
//	//iter1擎 pSt~部梱雖 給堅, iter2朝 iter1~部梱雖 絲棻.
//	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
//		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
//			//虜擒 iter1曖 ゎ敕高爾棻 iter2曖 ゎ敕高檜 渦 觼棻賊
//			if (iter1->avg < iter2->avg) {
//				//憮煎 夥脯遽棻.
//				Student p = *iter1;
//				*iter1 = *iter2;
//				*iter2 = p;
//			}
//		}
//	}
//	//ゎ敕高檜 偽擎 唳辦縑朝 措橫薄熱陛 贖 牖戲煎 薑溺п撿л.
//	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
//		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
//			//虜擒 ゎ敕高檜 偽堅,
//			if (iter1->avg == iter2->avg) {
//				//措橫薄熱陛 渦 觼棻賊
//				if (iter1->kor < iter2->kor) {
//					//舒 掘褻羹蒂 憮煎 夥脯邀.
//					Student p = *iter1;
//					*iter1 = *iter2;
//					*iter2 = p;
//				}
//			}
//		}
//	}
//	//ゎ敕高紫 偽堅, 措橫薄熱梱雖 偽擎 唳辦縑朝 艙橫薄熱陛 贖 牖戲煎 薑溺п撿л.
//	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
//		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
//			//ゎ敕高檜 偽堅,
//			if (iter1->avg == iter2->avg) {
//				//措橫薄熱紫 偽擎 唳辦縑
//				if (iter1->kor == iter2->kor) {
//					//艙橫薄熱蒂 綠掖ж罹 舒 掘褻羹蒂 夥脯邀.
//					if (iter1->eng < iter2->eng) {
//						Student p = *iter1;
//						*iter1 = *iter2;
//						*iter2 = p;
//					}
//				}
//			}
//		}
//	}
//}
//
////檣濠煎 嫡擎 舒 掘褻羹 寡翮 ん檣攪 滲熱 醞縑憮 醞除 蛔熱 з儅曖 ゎ敕檜 渦 堪擎 ん檣攪蒂 奩�納�.
//Student* select_out(Student* p, Student* q, int n)
//{
//;	//p曖 醞除 蛔熱 з儅曖 ゎ敕檜 q曖 醞除 蛔熱 з儅曖 ゎ敕爾棻 堪戲賊
//	if ((p+n/2)->avg > (q+n/2)->avg) {
//		//p蒂 奩��
//		return p;
//	}
//	//斜溢雖 彊擎 唳辦縑朝 q 奩��.
//	else if ((p+n/2)->avg < (q+n/2)->avg) {
//		return q;
//	}
//}

//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天

////��蘿 薑爾 殮溘 л熱
//int in_hotel_info(HOTEL* p)
//{	
//	//殮溘嫡擎 ��蘿曖 偃熱
//	int hotelCnt=0;
//	while (1) {
//		//檜葷擊 殮溘嫡擠
//		scanf("%s" ,&p->name);
//		//虜擒 0檜 殮溘腎歷棻賊 奩犒僥 驍轎
//		if (strcmp(p->name, "0") == 0) {
//			break;
//		}
//		//蛔晝, ゎっ, 剪葬, 褻衝んл罹睡(Y/N) 殮溘嫡擠
//		scanf("%d %lf %lf %c", &p->level, &p->reputation, &p->distance, &p->includeBreakfast);
//		//偃ч僥濠薯剪
//		getchar();
//		//殮溘 偃熱諦 ん檣攪 滲熱 1 隸陛衛霽.
//		hotelCnt++;
//		p++;
//	}
//	//譆謙瞳戲煎 殮溘 嫡擎 偃熱 奩��.
//	return hotelCnt;
//}
//
////轎溘辨 л熱
//void out_hotel_info(HOTEL* p, int N, int G, double D)
//{
//	//奩犒僥 牖�蛾� 掘褻羹ん檣攪 滲熱 摹樹
//	HOTEL *iter1, *iter2;
//	//試盪 ゎっ紫陛 堪擎 牖戲煎 薑溺п撿л
//	for (iter1 = p; iter1 < p + N; iter1++) {
//		for (iter2 = iter1; iter2 < p + N; iter2++) {
//			//奩犒僥擊 牖�裔炴棪� iter2曖 ゎっ檜 渦 堪棻賊 憮煎 夥脯邀.
//			if (iter1->reputation < iter2->reputation) {
//				HOTEL tmp = *iter1;
//				*iter1 = *iter2;
//				*iter2 = tmp;
//			}
//		}
//	}
//	//ゎっ紫 牖戲煎 薑溺脹 寡翮縑憮 餌瞪縑憮 緒艇 牖戲煎 薑溺
//	for (iter1 = p; iter1 < p + N; iter1++) {
//		for (iter2 = iter1; iter2 < p + N; iter2++) {
//			//虜擒 ゎっ紫陛 偽堅
//			if (iter1->reputation == iter2->reputation) {
//				//餌瞪牖戲煎 緒腦棻賊 憮煎 夥脯邀.
//				if (strcmp(iter1->name, iter2->name)>0) {
//					HOTEL tmp = *iter1;
//					*iter1 = *iter2;
//					*iter2 = tmp;
//				}
//			}
//		}
//	}
//	//蛔晝檜 G爾棻 觼剪釭 偽堅, 剪葬陛 D爾棻 濛剪釭 偽擎 ��蘿菟曖 薑爾蒂 轎溘л.
//	for (iter1 = p; iter1 < p + N; iter1++) {
//		if (iter1->level >= G) {
//			if (iter1->distance <= D) {
//				printf("%s %d %.1f %.1f %c\n",iter1->name, iter1->level, iter1->reputation, iter1->distance, iter1->includeBreakfast);
//			}
//		}
//	}
//}

//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天

////殮溘辨 л熱
//void input(PARKING_INFO* p, int n)
//{
//	//奩犒僥 牖�蛾� ん檣攪滲熱 摹樹
//	PARKING_INFO *iter;
//	for (iter = p; iter < p + n; iter++) {
//		//離 廓��, ア 廓��, 鼻ヶ 謙盟 殮溘嫡擠.
//		scanf("%d %d %c ",&iter->carNum, &iter->phoneNum, &iter->product);
//		//虜擒 鼻ヶ謙盟陛 S塭賊, 薑晦掏 爾嶸罹睡諦 薑晦掏 謙盟蒂 殮溘嫡擠
//		if (iter->product == 'S') {
//			scanf("%c %d ", &iter->isRegular, &iter->regularDay);
//		}
//		//輿離 衛除 殮溘嫡擠.
//		scanf("%d",&iter->parkingTime);
//		getchar();
//	}
//}
//
////輿離 綠辨 啗骯 л熱
//void compute(PARKING_INFO* p)
//{
//	//試盪 薑晦掏 嶸鼠縑 渠и 綠辨擊 試盪 啗骯п遽棻.
//	//虜擒 鼻ヶ檜 S檣 唳辦
//	if (p->product == 'S') {
//		//薑晦掏擊 陛雖堅 氈棻賊
//		if (p->isRegular == 'Y') {
//			//蟾婁 衛除縑 渠и 啗骯虜 ж賊 腎嘎煎 罹晦憮朝 嬴鼠濛機紫 ж雖 彊朝棻.
//		}
//		//薑晦掏擊 陛雖堅 氈雖 彊棻賊
//		else if (p->isRegular == 'N') {
//			//7橾 薑晦掏 綠辨擊 cost縑 蹺陛п邀.
//			if (p->regularDay == 7) {
//				p->cost += 30000;
//			}
//			//30橾 薑晦掏 綠辨擊 cost縑 蹺陛п邀.
//			else if (p->regularDay == 30) {
//				p->cost += 100000;
//			}
//			//180橾 薑晦掏 綠辨擊 cost縑 蹺陛п邀.
//			else if (p->regularDay == 180) {
//				p->cost += 500000;
//			}
//		}
//	}
//	//虜擒 鼻ヶ檜 D檣 唳辦
//	else if (p->product == 'D') {
//		//橾橾掏 綠辨 5000錳虜 cost縑 蹺陛п遽棻.
//		p->cost += 5000;
//	}
//	//虜擒 輿離衛除檜 4衛除, 闊 240碟擊 剩橫 除棻賊
//	if (p->parkingTime > 240) {
//		//240碟檜 剩橫陛賊 10碟葆棻 200錳檜嘎煎 試盪 輿離衛除縑憮 240擊 貍輿堅,
//		int time = (p->parkingTime) - 240;
//		//斜 高擊 10戲煎 釭換 棻擠 200擊 培п憮 cost縑 渦п遽棻.
//		int tmp = time / 10;
//		p->cost += (tmp * 200);
//	}
//}
//
////轎溘辨 л熱
//void display(PARKING_INFO* p, int n)
//{
//	//奩犒僥 牖�蛾� ん檣攪滲熱
//	PARKING_INFO *iter;
//	//橾橾掏 綠辨 м啗, 薑晦掏 綠辨 м啗蒂 盪濰й 滲熱
//	double Dsum=0, Ssum=0;
//	for (iter = p; iter < p + n; iter++) {
//		//奩犒僥 牖�裔牉曌� 離 廓��, ア 廓��, 鼻ヶ 謙盟, 輿離 綠辨 轎溘п遽棻.
//		printf("%d %d %c %.0f\n",iter->carNum, iter->phoneNum, iter->product, iter->cost);
//		//鼻ヶ 謙盟陛 D塭賊 橾橾掏 綠辨м啗縑 輿離 綠辨擊 渦п輿堅
//		if(iter->product == 'D')
//			Dsum += iter->cost;
//		//鼻ヶ 謙盟陛 S塭賊 薑晦掏 綠辨м啗縑 輿離 綠辨擊 渦п遽棻.
//		else if(iter->product == 'S')
//			Ssum += iter->cost;
//	}
//	//Dм啗, Sм啗, 輿離 綠辨 識м(D+S)蒂 轎溘п遽棻.
//	printf("%.1f %.1f %.1f",Dsum,Ssum, Dsum+Ssum);
//}
//
////輿離 薑爾 薑溺 л熱
//void parking_info_sort(PARKING_INFO* p, int n)
//{
//	//奩犒僥 牖�蛾� 滲熱 摹樹
//	PARKING_INFO *x, *y;
//	//試盪 鼻ヶ 謙盟渠煎 薑溺п遽棻.
//	for (x = p; x < p + n; x++) {
//		for (y = x; y < p + n; y++) {
//			//D陛 試盪 釭螃堅, 斜 棻擠 S陛 釭諦撿л.
//			if (x->product > y->product) {
//				PARKING_INFO tmp = *x;
//				*x = *y;
//				*y = tmp;
//			}
//		}
//	}
//	//鼻ヶ 謙盟渠煎 薑溺ж堅 釭賊 離 廓�ㄣ賰� 薑溺п遽棻.
//	for (x = p; x < p + n; x++) {
//		for (y = x; y < p + n; y++) {
//			//鼻ヶ曖 謙盟陛 偽擎 唳辦縑
//			if (x->product == y->product) {
//				//離 廓�ㄣ賰� 薑溺п遽棻.
//				if (x->carNum > y->carNum) {
//					PARKING_INFO tmp = *x;
//					*x = *y;
//					*y = tmp;
//				}
//			}
//		}
//	}
//	
//}

//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天

//殮溘 л熱
void inputStudent()
{	
	//з儅 掘褻羹滲熱 摹樹
	Student tmp;
	//鏃菜 з薄 0戲煎 蟾晦��
	tmp.point=0;
	//檜葷, з廓, 婁跡 熱 殮溘嫡擠
	scanf("%s %d %d",&tmp.name, &tmp.id, &tmp.gradeCnt);
	//婁跡 熱 虜躑 奩犒п憮 婁跡檜葷婁 斜 婁跡曖 з薄 殮溘嫡擠
	for (int i = 0; i < tmp.gradeCnt; i++) {
		double p;
		scanf("%s %lf",&tmp.grade[i], &p);
		//婁跡曖 з薄擊 識 з薄縑 渦п遽棻.
		tmp.point += p;
	}
	//偃ч僥濠 薯剪
	getchar();
	//掘褻羹 寡翮縑 掘褻羹滲熱 蹺陛
	students[studentCnt] = tmp;
	//з儅 熱 1隸陛衛霽.
	studentCnt++;
}

//薑溺 л熱
void sortStudent(Student arr[], int cnt)
{
	//錳楚 л熱朝 斜渠煎 舒橫撿 ж嘎煎 億煎遴 掘褻羹 寡翮擊 ж釭 摹樹п憮 檜 寡翮縑 高菟擊 犒餌и 棻擠 薑溺ж罹 轎溘л.
	Student newArr[100];
	int i,j;
	//億煎遴 寡翮縑 掘褻羹 犒餌
	for (i = 0; i < cnt; i++) {
		newArr[i] = arr[i];
	}
	//億煎遴 寡翮擊 檜葷 牖戲煎 薑溺п遽棻.
	for (i = 0; i < cnt; i++) {
		for (j = i; j < cnt; j++) {
			//虜擒 檜葷檜 餌瞪 牖戲煎 擅檜塭賊
			if (strcmp(newArr[i].name, newArr[j].name)>0) {
				//掘褻羹 詹幗蒂 夥脯遽棻.
				Student tmp = newArr[i];
				newArr[i] = newArr[j];
				newArr[j] = tmp;
			}
		}
	}
	//轎溘л熱 碳楝諦憮 億煎遴 寡翮 轎溘
	printStudent(newArr,cnt);
}

//з儅 餉薯 л熱
void deleteStudent()
{
	//餉薯ж堅濠 ж朝 檜葷擊 殮溘嫡擊 滲熱
	char findName[31];
	//檜葷 殮溘嫡堅 偃ч僥濠 薯剪
	scanf("%s",&findName);
	getchar();
	for (int i = 0; i < studentCnt; i++) {
		//寡翮 牖�� ж賊憮 殮溘 嫡擎 檜葷擊 瓊擎 唳辦
		if (strcmp(students[i].name, findName) == 0) {
			//瓊擎 嬪纂睡攪 寡翮曖 部梱雖 и 蘊噶 擅戲煎 渡梯.
			for (int j = i; j < studentCnt-1; j++) {
				students[j] = students[j+1];
			}
			//з儅 熱 1 馬模衛霽.
			studentCnt--;
		}
	}
}

//轎溘 л熱
void printStudent(Student arr[], int cnt)
{
	//掘褻羹 寡翮擊 牖�裔牉� 檜葷, з廓, 婁跡熱, 瞪羹 ゎ薄 轎溘п邀.
	for (int i = 0; i < cnt; i++) {
		printf("%s %d %d %.2f\n",arr[i].name, arr[i].id, arr[i].gradeCnt, arr[i].point/arr[i].gradeCnt);
	}
}
