#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//구조체 선언
typedef struct student {
	char* name;		//이름
	int firstStage;	//1단계 점수
	int interview;	//면접 점수
	double sum;		//총점
}Student;
int main() {
	//n,m 선언
	int n, m;
	scanf("%d %d", &n, &m);		//n,m 입력받음
	getchar();	//개행문자 제거

	//구조체 배열 메모리 할당
	Student* stus = (Student*)malloc(sizeof(Student) * n);

	//반복문 순회용 변수
	int i, j;
	for (i = 0; i < n; i++) {
		//이름 저장용 문자열변수
		char name[101];
		//이름, 1단계 점수, 면접 점수 입력받음
		scanf("%s %d %d", name, &stus[i].firstStage, &stus[i].interview);
		//개행 문자 제거
		getchar();
		//구조체 멤버 이름 변수 메모리 할당
		stus[i].name = (char*)malloc(sizeof(char)*(strlen(name)+1));
		//문자열 복사함
		strcpy(stus[i].name, name);
		//총점을 1단계점수*7 + 면접 점수*3 로 초기화함(나중에 출력할 때 10으로 나눠서 출력할 예정)
		stus[i].sum = stus[i].firstStage*7 + stus[i].interview*3;
	}

	//총점 기준으로 내림차순 정렬하는 코드
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			//stus[i]의 점수와 stus[j]의 점수를 비교해서 더 큰것을 앞에 오게함
			if (stus[i].sum < stus[j].sum) {
				//선택정렬
				Student tmp = stus[i];
				stus[i] = stus[j];
				stus[j] = tmp;
			}
		}
	}
	//총점이 같으면 1단계 점수 기준으로 정렬해야함
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			//만약 총점이 같다면,
			if (stus[i].sum == stus[j].sum) {
				//1단계 점수를 기준으로 정렬해준다.
				if (stus[i].firstStage < stus[j].firstStage) {
					//둘 중 더 큰 값을 가진 구조체 배열의 요소가 앞에 오게 함.(선택정렬)
					Student tmp = stus[i];
					stus[i] = stus[j];
					stus[j] = tmp;

				}
			}
		}
	}
	//총점도 같고, 1단계 점수도 같으면 이름을 사전순으로 정렬해야 한다.
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			//만약 총점이 같고,
			if (stus[i].sum == stus[j].sum) {
				//1단계 점수도 같다면
				if (stus[i].firstStage == stus[j].firstStage) {
					//사전순으로 빠른 이름이 앞에 오게 정렬함.
					if (strcmp(stus[i].name, stus[j].name) > 0) {
						//두 값을 바꾸는 코드(선택 정렬)
						Student tmp = stus[i];
						stus[i] = stus[j];
						stus[j] = tmp;

					}
				}
			}
		}
	}

	//m명의 합격자를 선발하지만, 총점도 같고 1단계점수도 같은 사람은 모두 선발함.
	//i=m 부터 시작해서 i-1과 i를 비교해서 1단계 점수가 같은 동안 i를 1씩 증가시킴
	for (i = m; i < n; i++) {
		if (stus[i-1].firstStage != stus[i].firstStage) {
			//만약 i-1과 i의 1단계 점수가 다르다면, 반복문 탈출.
			break;
		}
	}
	//m=i로 바꿔준다.
	m=i;

	//0부터 m까지 출력해준다.
	for (i = 0; i < m; i++) {
		printf("%s %d %d %.1f\n",stus[i].name, stus[i].firstStage, stus[i].interview, stus[i].sum/10);
	}
	//마지막엔 총 합격자수 출력.
	printf("%d",m);

	//구조체 배열의 각 멤버변수에 저장된 이름을 메모리 할당 해제해준다.
	for (i = 0; i < n; i++) {
		free(stus[i].name);
	}
	//마지막으로 구조체 배열을 메모리 할당 해제해준다.
	free(stus);
}