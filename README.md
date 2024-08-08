# ConcurrentMemoryPool-AI

## Concurrent Memory Pool with Deep Learning Example

### 프로젝트 소개
고병렬 메모리 풀 및 딥러닝 예제 프로젝트는 고병렬 환경에서 메모리 할당 및 해제 요구를 효과적으로 관리하는 솔루션을 제공합니다. 이 프로젝트는 사용자 정의 메모리 풀 관리자를 구현하여 스레드 캐시, 중앙 캐시 및 페이지 캐시를 결합하여 메모리 작업의 효율성을 크게 향상시킵니다. 또한, 사용자 정의 메모리 할당자의 실제 적용 성능을 보여주는 딥러닝 신경망 예제도 포함되어 있습니다.

### 주요 특징
효율적인 메모리 할당 및 해제: 사용자 정의 메모리 풀을 통해 메모리 관리의 효율성을 높이고, 메모리 할당 및 해제 시간을 크게 줄입니다.
고병렬 환경 지원: 스레드 안전한 메모리 할당 및 해제 메커니즘을 통해 고병렬 환경에서도 안정적인 성능을 보장합니다.
딥러닝 예제 응용: 딥러닝 신경망 훈련 예제를 포함하여, 실제 응용에서 사용자 정의 메모리 할당자의 장점을 보여줍니다.
성능 테스트: 벤치마크 테스트를 통해 사용자 정의 메모리 할당자와 표준 메모리 할당자의 성능을 비교합니다.

### 기술 스택
프로그래밍 언어: C++
빌드 도구: Visual Studio 2019
테스트 프레임워크: Visual Studio 2019
딥러닝 라이브러리: FNN 신경망 

### 프로젝트 구조
ConcurrentMemoryPool/
├── ConcurrentMemoryPool/
│   ├── CentralCache.h
│   ├── Common.h
│   ├── ConcurrentAlloc.h
│   ├── ObjectPool.h
│   ├── PageCache.h
│   ├── PageMap.h
│   ├── ThreadCache.h
│   ├── NeuralNetwork.h
│   ├── CentralCache.cpp
│   ├── PageCache.cpp
│   ├── ThreadCache.cpp
│   ├── Benchmark.cpp
│   ├── UnitTest.cpp
│   ├── NeuralNetwork.cpp
│   ├── main.cpp
├── AIProject/
│   ├── NeuralNetwork.h
│   ├── NeuralNetwork.cpp
│   ├── main.cpp
│   ├── ConcurrentAlloc.h
├── lib/
│   ├── ConcurrentMemoryPool.lib
│   └── ConcurrentMemoryPool.pdb

### 고병렬 메모리 풀 구현
서문
고성능 컴퓨팅과 병렬 프로그래밍에서는 메모리 관리 시스템의 효율성이 매우 중요합니다. 본 프로젝트는 효율적인 메모리 관리 시스템을 설계하고 구현하는 것을 목표로 하며, 주요 구성 요소로 CentralCache, PageCache, ThreadCache를 포함하고 있습니다. 이러한 구성 요소의 협력을 통해 메모리 할당 및 해제 메커니즘을 최적화하고 시스템 성능을 향상시켰습니다.

# 구성 요소 개요
CentralCache: PageCache에서 할당된 대용량 메모리를 관리하고 이를 잘게 나누어 ThreadCache에 제공합니다.
PageCache: 운영 체제에서 대용량 메모리를 신청하고 해제하며 이를 CentralCache에 할당합니다.
ThreadCache: 각 스레드가 독점하는 메모리 캐시로, CentralCache에서 메모리 블록을 받아와 메모리 할당의 락 경쟁을 줄입니다.

# 주요 구현 세부 사항

## CentralCache
CentralCache는 대용량 메모리를 잘게 나누어 ThreadCache에 제공하는 역할을 합니다. 이 클래스는 싱글톤 패턴을 사용하여 전역적으로 유일한 인스턴스를 보장합니다.
![image](https://github.com/user-attachments/assets/201f300a-3037-4fac-93ab-3ee093e337c9)

## PageCache
PageCache는 운영 체제에서 대용량 메모리를 신청하고 해제하며 이를 CentralCache에 할당합니다. 이 클래스도 싱글톤 패턴을 사용합니다.
![image](https://github.com/user-attachments/assets/97f16607-f4d4-4e88-a61c-11be296e40d8)

## ThreadCache
ThreadCache는 각 스레드에 독립적인 메모리 캐시를 제공하여 락 경쟁 문제를 방지합니다. CentralCache를 통해 메모리 블록을 가져옵니다.
![image](https://github.com/user-attachments/assets/6f6f482e-1ffb-4231-a121-fb1d0430eee0)

## 메모리 할당 및 해제
ConcurrentAlloc 및 ConcurrentFree 함수는 스레드 안전한 메모리 할당 및 해제를 제공합니다.
![image](https://github.com/user-attachments/assets/cc9dee09-c2e2-4fd6-af13-de6a03784d69)
![image](https://github.com/user-attachments/assets/4b086388-fa4b-4f20-8daf-ba96c570d469)

## 단위 테스트 및 성능 테스트
단위 테스트와 성능 테스트를 통해 메모리 관리 시스템의 정확성과 효율성을 검증했습니다.
![image](https://github.com/user-attachments/assets/e243e3d9-49e5-4658-a659-b19232fd6857)
![image](https://github.com/user-attachments/assets/b69bd379-3f45-47bd-9727-c5487594eac3)

CentralCache, PageCache, ThreadCache의 설계 및 구현을 통해 우리는 효율적인 메모리 관리 시스템을 구축했습니다. 이를 통해 메모리 할당 및 해제의 효율성을 크게 향상시키고, 메모리 조각화를 줄였으며, 다중 스레드 환경에서 우수한 성능을 발휘했습니다. 이러한 개선은 고성능 컴퓨팅과 병렬 프로그래밍에 중요한 의미를 갖습니다.

# 결과
![image](https://github.com/user-attachments/assets/b2d4b0b8-878b-4eeb-bcad-f9df8d57bbde)
# 테스트 환경
4개의 스레드가 동시에 10번의 라운드를 실행.
각 라운드에서 100,000번의 malloc, free, ConcurrentAlloc, ConcurrentFree를 수행.

# 성능 결과
ConcurrentAlloc & ConcurrentFree 테스트
4개의 스레드가 10라운드 동안 각 라운드에서 100,000번의 ConcurrentAlloc을 수행하는 데 걸린 시간: 2449 ms
4개의 스레드가 10라운드 동안 각 라운드에서 100,000번의 ConcurrentFree를 수행하는 데 걸린 시간: 1338 ms
4개의 스레드가 10라운드 동안 총 4,000,000번의 ConcurrentAlloc 및 ConcurrentFree를 수행하는 데 걸린 총 시간: 3787 ms

malloc & free 테스트
4개의 스레드가 10라운드 동안 각 라운드에서 100,000번의 malloc을 수행하는 데 걸린 시간: 6966 ms
4개의 스레드가 10라운드 동안 각 라운드에서 100,000번의 free를 수행하는 데 걸린 시간: 3589 ms
4개의 스레드가 10라운드 동안 총 4,000,000번의 malloc 및 free를 수행하는 데 걸린 총 시간: 10555 ms

# 결론
ConcurrentAlloc과 ConcurrentFree 함수가 전통적인 malloc 및 free 함수보다 훨씬 빠르게 수행됨.
ConcurrentAlloc 및 ConcurrentFree 함수가 malloc 및 free 함수보다 약 2.8배 더 빠름.
이는 병렬 환경에서 메모리 할당 및 해제의 효율성을 크게 향상시킴을 의미함.
이 결과는 ConcurrentAlloc 및 ConcurrentFree 함수가 병렬 환경에서 메모리 조각화를 줄이고, 더 효율적인 메모리 사용을 가능하게 하며, 성능 측면에서 큰 이점을 제공함을 보여줍니다. 이는 고성능 컴퓨팅과 병렬 프로그래밍에 있어서 중요한 의미를 갖습니다.


# Deep Learning Example
아래에서는 고병렬 메모리 프로젝트 를 FNN 신경망에 추가하여 일련의 실험을 수행하고, 고병렬 메모리가 모델의 학습 속도를 향상시킬 수 있음을 증명할 것입니다.

# 고병합 프로젝트 정적 라이브러리 생성 요약

# 프로젝트 속성 구성:

# 일반 속성:
프로젝트 속성에서 "일반" 옵션을 선택하고 "구성 유형"을 "정적 라이브러리(.lib)"로 설정합니다.

# C/C++ 속성:
"C/C++" -> "일반" 옵션에서 "추가 포함 디렉터리"에 헤더 파일 경로가 포함되어 있는지 확인합니다.

# 링커 속성:
"링커" -> "일반" 옵션에서 "추가 라이브러리 디렉터리"에 라이브러리 파일 경로가 포함되어 있는지 확인합니다.
"링커" -> "입력" 옵션에서 "추가 종속 항목"에 필요한 라이브러리 파일이 포함되어 있는지 확인합니다.

# 정적 라이브러리 생성:
프로젝트에 필요한 소스 코드와 헤더 파일을 작성하여 프로젝트가 성공적으로 컴파일되도록 합니다.
프로젝트를 빌드하고 생성된 디렉터리를 확인하여 .lib 파일이 생성되었는지 확인합니다.

# 신경망 프로젝트에 통합:
신경망 프로젝트에 생성된 정적 라이브러리 파일과 관련 헤더 파일을 도입합니다.
신경망 코드에서 사용자 정의 메모리 할당기를 사용하여 메모리 관리를 수행합니다.

# 테스트 케이스 작성 및 실행:
신경망 훈련 코드를 작성하고 사용자 정의 메모리 할당기와 기본 메모리 할당기를 사용하여 비교 테스트를 수행합니다.
테스트 코드를 실행하고 훈련 시간과 메모리 할당 및 해제 시간을 기록합니다

# 성능 테스트: 사용자 정의 메모리 할당기와 기본 메모리 할당기의 비교
사용자 정의 메모리 할당기를 통해 메모리 관리의 효율성을 극대화하고, 이를 통해 FNN 신경망의 학습 속도를 향상시킬 수 있음을 실험을 통해 검증하였습니다.

# 주요 코드
ConcurrentAlloc.h: 커스텀 메모리 할당자 구현
NeuralNetwork.h 및 NeuralNetwork.cpp: 신경망 클래스 정의 및 구현
main.cpp: 실험을 수행하는 메인 함수

# main.cpp
![image](https://github.com/user-attachments/assets/b7d1ef2c-1e67-42d0-a54a-0f489f1609e9)
![image](https://github.com/user-attachments/assets/91992121-2086-4a54-8b0b-7d649b64211e)
FNN을 이용하여 세 가지의 간단-중간-복잡한 신경망을 정의하여 테스트를 수행하였습니다


# Dataset Size: 10000

# Simple Neural Network
![image](https://github.com/user-attachments/assets/d0d62cda-5eb5-4bbc-a012-4ebdc5b4504d)
![image](https://github.com/user-attachments/assets/d777c60f-090d-4823-8c72-98bbeda0fe30)
![image](https://github.com/user-attachments/assets/01b66215-9723-42a3-ab81-0f69c3ff1a41)

# Medium Neural Network
![image](https://github.com/user-attachments/assets/f2b36ce2-db7e-4f6f-862d-92c9e2bea310)
![image](https://github.com/user-attachments/assets/e1d9913b-1a5a-4cdd-9dee-53466fcbd6ef)
![image](https://github.com/user-attachments/assets/74628861-43cf-42f3-bfa2-6c9423d60512)

# Complex Neural Network
![image](https://github.com/user-attachments/assets/1113453e-b70b-4cdb-b4e5-555bfb3342ee)
![image](https://github.com/user-attachments/assets/0c8e3765-c2fb-422c-ae3d-a71fc4c4f9ff)
![image](https://github.com/user-attachments/assets/ddc05a6d-e075-4daf-a180-91a3219b13a4)

# Dataset Size: 50000

# Simple Neural Network
![image](https://github.com/user-attachments/assets/59f75fdc-8290-4e01-831c-cb22dcf7cb2c)
![image](https://github.com/user-attachments/assets/cfc80309-a234-435d-be75-2af5fd70bc08
![image](https://github.com/user-attachments/assets/9b3a4b31-e1c3-43aa-b896-2ad2b9e7fb09)

# Medium Neural Network
![image](https://github.com/user-attachments/assets/8f2814f3-68c2-49ed-b122-4131c03a281d)
![image](https://github.com/user-attachments/assets/f6896eca-2ad0-4de8-8c80-524410267b32)
![image](https://github.com/user-attachments/assets/1862e7d8-ff95-461c-9434-3727c4265542)

# Complex Neural Network
![image](https://github.com/user-attachments/assets/67665eba-666f-4954-86f4-9eeb8c7e556a)
![image](https://github.com/user-attachments/assets/47453f9f-1639-4928-8371-da908cd82973)
![image](https://github.com/user-attachments/assets/07f5b8a6-072f-4347-b8a4-2e74ede03ed9)

# Dataset Size: 100000

# Simple Neural Network
![image](https://github.com/user-attachments/assets/68e6caa1-53ef-4a45-b539-72ccf534f88e)
![image](https://github.com/user-attachments/assets/d3703d7e-c0c4-44bc-a7cf-738fbdfd93d3)
![image](https://github.com/user-attachments/assets/0863bcb0-ab9c-4917-b46f-10e773fe2a7a)

# Medium Neural Network
![image](https://github.com/user-attachments/assets/ddb7d7fd-bf59-46f2-b192-89ccbc2a3701)
![image](https://github.com/user-attachments/assets/c9bf09f7-f7f9-4903-8f57-2521242e9a0c)
![image](https://github.com/user-attachments/assets/68879fe1-7aaa-499e-ba4a-c6488c0bb786)

# Complex Neural Network
![image](https://github.com/user-attachments/assets/d8dd5ba8-936c-49a3-be6f-c86e2432fd85)
![image](https://github.com/user-attachments/assets/371b10fb-4aaa-4818-b10c-d58df785c03d)
![image](https://github.com/user-attachments/assets/8894be71-cd79-4371-a30d-248e2804e3f4)

# 실험 결과 분석
데이터 세트 크기: 10000

간단한 신경망
맞춤형 할당기 훈련 시간: 1.2797 초
기본 할당기 훈련 시간: 4.8105 초
결과 분석: 간단한 신경망에서 맞춤형 메모리 할당기가 훈련 속도를 약 3.75배 향상시켰습니다.

중간 복잡도 신경망
맞춤형 할당기 훈련 시간: 1.30891 초
기본 할당기 훈련 시간: 4.89905 초
결과 분석: 중간 복잡도의 신경망에서도 맞춤형 메모리 할당기가 훈련 속도를 약 3.74배 향상시켰습니다.

복잡한 신경망
맞춤형 할당기 훈련 시간: 1.45208 초
기본 할당기 훈련 시간: 5.15708 초
결과 분석: 복잡한 신경망에서도 맞춤형 메모리 할당기가 훈련 속도를 약 3.55배 향상시켰습니다.

데이터 세트 크기: 50000

간단한 신경망
맞춤형 할당기 훈련 시간: 5.79534 초
기본 할당기 훈련 시간: 23.847 초
결과 분석: 간단한 신경망에서 맞춤형 메모리 할당기가 훈련 속도를 약 4.11배 향상시켰습니다.

중간 복잡도 신경망
맞춤형 할당기 훈련 시간: 6.38426 초
기본 할당기 훈련 시간: 24.4181 초
결과 분석: 중간 복잡도의 신경망에서도 맞춤형 메모리 할당기가 훈련 속도를 약 3.82배 향상시켰습니다.

복잡한 신경망
맞춤형 할당기 훈련 시간: 7.2771 초
기본 할당기 훈련 시간: 25.6934 초
결과 분석: 복잡한 신경망에서도 맞춤형 메모리 할당기가 훈련 속도를 약 3.53배 향상시켰습니다.

데이터 세트 크기: 100000

간단한 신경망
맞춤형 할당기 훈련 시간: 12.5057 초
기본 할당기 훈련 시간: 48.1206 초
결과 분석: 간단한 신경망에서 맞춤형 메모리 할당기가 훈련 속도를 약 3.85배 향상시켰습니다.

중간 복잡도 신경망
맞춤형 할당기 훈련 시간: 12.9302 초
기본 할당기 훈련 시간: 49.9014 초
결과 분석: 중간 복잡도의 신경망에서도 맞춤형 메모리 할당기가 훈련 속도를 약 3.86배 향상시켰습니다.

복잡한 신경망
맞춤형 할당기 훈련 시간: 15.9967 초
기본 할당기 훈련 시간: 54.2551 초
결과 분석: 복잡한 신경망에서도 맞춤형 메모리 할당기가 훈련 속도를 약 3.39배 향상시켰습니다.

# 결론
C++ 고성능 동시 메모리 할당기가 신경망 훈련 속도를 향상시키는 데 효과적임을 확인했습니다. 맞춤형 할당기는 메모리 할당 및 해제 성능에서 기본 할당기보다 우수하며, 특히 대규모 데이터 및 복잡한 계산 작업을 처리할 때 그 성능이 더욱 두드러집니다. 이 결과는 미래의 메모리 관리 전략을 최적화하는 데 중요한 지원을 제공하며, 인공지능 및 고성능 컴퓨팅 분야의 연구에 중요한 참고 자료가 될 것입니다.


















































