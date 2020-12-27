#include <stdio.h>

int GetWinterSensoryTemp(int temperature, int wind_speed) {
  switch(wind_speed) {
      case 0:
        wind_speed = 4;
        break;
      case 1:
        wind_speed = 1;
       break;
      case 2:
        wind_speed = 8;
        break;
    }

    return temperature - 0.6 * wind_speed;
}

int GetSummerSensoryTemp(int temperature, int humidity) {
  switch(humidity) {
  case 0:
    return temperature;
    break;
  case 1:
    return temperature - 3;
    break;
  case 2:
    return temperature + 3;
    break;
  }
  return temperature;
}

void RecommendClothes(int sensory_temp, int weather) {
  char clothes_over_28[100] = "민소매, 반팔, 반바지, 원피스";
  char clothes_23_27[100] = "반팔, 얇은 셔츠, 반바지, 면바지";
  char clothes_20_22[100] = "얇은 가디건, 긴팔 면바지, 청바지";
  char clothes_17_19[100] = "얇은 니트, 맨투맨, 가디건, 청바지";
  char clothes_12_16[100] = "자켓, 가디건, 야상 스타킹, 청바지, 면바지";
  char clothes_9_11[100] = "자켓, 트렌치코트, 야상 니트, 청바지, 스타킹";
  char clothes_5_8[100] = "코트, 가죽자켓, 히트텍, 니트, 레깅스";
  char clothes_lower_4[100] = "패딩, 두꺼운 코트, 목도리, 기모제품";
  char clothes_rain[100] = "부츠, 반바지, 7부 바지, 가디건";
  char clothes_snow[100] = "부츠, 밝은 색 옷, 방수 패딩, 모자, 장갑";
  char clothes_dust[100] = "마스크, 모자, 안경, 긴 소매 옷, 바람막이";

  printf("\n기온 맞춤형 의복은 다음과 같습니다.\n\n");
  printf("===========================================\n");
  if(sensory_temp >= 28) printf("%s\n", clothes_over_28);
  else if(sensory_temp >= 23) printf("%s\n", clothes_23_27);
  else if(sensory_temp >= 20) printf("%s\n", clothes_20_22);
  else if(sensory_temp >= 17) printf("%s\n", clothes_17_19);
  else if(sensory_temp >= 12) printf("%s\n", clothes_12_16);
  else if(sensory_temp >= 9) printf("%s\n", clothes_9_11);
  else if(sensory_temp >= 5) printf("%s\n", clothes_5_8);
  else printf("%s\n", clothes_lower_4);
  printf("===========================================\n");

  printf("\n조금 더 덥게 입을 수도 있어요.\n\n");
  printf("===========================================\n");
  if(sensory_temp >= 28) printf("%s\n", clothes_23_27);
  else if(sensory_temp >= 23) printf("%s\n", clothes_20_22);
  else if(sensory_temp >= 20) printf("%s\n", clothes_17_19);
  else if(sensory_temp >= 17) printf("%s\n", clothes_12_16);
  else if(sensory_temp >= 12) printf("%s\n", clothes_9_11);
  else if(sensory_temp >= 9) printf("%s\n", clothes_5_8);
  else if(sensory_temp >= 5) printf("%s\n", clothes_lower_4);
  else printf("더 껴입을 옷이 없습니다..\n");
  printf("===========================================\n");

  printf("\n조금 더 춥게 입을 수도 있어요.\n\n");
  printf("===========================================\n");
  if(sensory_temp >= 28) printf("더 벗을 옷이 없습니다..\n");
  else if(sensory_temp >= 23) printf("%s\n", clothes_over_28);
  else if(sensory_temp >= 20) printf("%s\n", clothes_23_27);
  else if(sensory_temp >= 17) printf("%s\n", clothes_20_22);
  else if(sensory_temp >= 12) printf("%s\n", clothes_17_19);
  else if(sensory_temp >= 9) printf("%s\n", clothes_12_16);
  else if(sensory_temp >= 5) printf("%s\n", clothes_9_11);
  else printf("%s\n", clothes_5_8);
  printf("===========================================\n");

  printf("\n기상 상황에 맞춰 다음도 고려해 보세요.\n\n");
  printf("===========================================\n");
  switch(weather) {
    case 0:
      printf("딱히 신경써야 할 건 없네요!\n");
      break;
    case 1:
      printf("%s\n", clothes_rain);
      break;
    case 2:
      printf("%s\n", clothes_snow);
      break;
    case 3:
      printf("%s\n", clothes_dust);
      break;
  }
  printf("===========================================\n");
}

int main() {
  int season, temperature, wind_speed, humidity, weather;
  int sensory_temp;

  printf("계절을 입력해 주세요\n");
  printf("(봄/가을 : 1, 여름 : 2, 겨울 : 3)\n");
  scanf("%d", &season);

  printf("\n기온을 입력해 주세요(℃ )\n");
  scanf("%d", &temperature);

  if(season == 3) {
    printf("\n바람 세기는 얼마나 되나요?\n");
    printf("(스킵/보통 : 0, 없음/느림 : 1 , 빠름 : 2)\n");
    scanf("%d", &wind_speed);

    sensory_temp = GetWinterSensoryTemp(temperature, wind_speed);
  }
  
  else if(season == 2) {
    printf("\n오늘은 습한가요?\n");
    printf("(스킵/보통 : 0, 건조함 : 1, 습함 : 2)\n");
    scanf("%d", &humidity);

    sensory_temp = GetSummerSensoryTemp(temperature, humidity);
  }

  else if(season == 1) {
    sensory_temp = temperature;
  }

  printf("\n특별한 기상 상황이 있나요?\n");
  printf("(스킵/없음 : 0, 비 : 1, 눈 : 2, 미세먼지 : 3)\n");
  scanf("%d", &weather);

  RecommendClothes(sensory_temp, weather);

  return 0;
}