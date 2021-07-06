<!-- PROJECT LOGO -->
<br />
<p align="center">
  

  <h1 style="font-size:30pt" align="center">42 Assignment Checker</h1>

  <p align="center">
    42 서울 과제를 check 명령어 단 하나로 검사하세요!!<br><br>
  <a href="https://github.com/S-um/42assignment_checker">
    <img src="Images/42assignment_checker.png" alt="Logo">
  </a>
  </p>
</p>

<br><br>

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><b>Table of Contents</b></summary>
  <ol>
    <li>
      <a href="#설치-방법">설치 방법</a>
      <ul>
        <li><a href="#맥-zsh-에서">맥 zsh 에서 설치</a></li>
        <li><a href="#ubuntu-bashsh-에서">우분투 bash 에서 설치</a></li>
      </ul>
    </li>
    <li>
      <a href="#사용-방법">사용 방법</a>
    </li>
    <li>
      <a href="#출력-형식">출력 형식</a>
    </li>
  </ol>
</details>

<br><br><br>
<!-- GETTING STARTED -->

## **설치 방법**

### **맥 zsh 에서**

```
git clone https://github.com/S-um/42assignment_checker
cd 42assignment_checker
./installchecker.sh
source ~/.zshrc
```
위 커맨드를 터미널에 입력

### **ubuntu bash 에서**

```
git clone https://github.com/S-um/42assignment_checker
cd 42assignment_checker
./installchecker_bash.sh
source ~/.bashrc
```
위 커맨드를 터미널에 입력

## **사용 방법**

**norminette 가 설치되어 있어야 사용 가능합니다!!**

확인하려는 c 과제 디렉토리 (`.git` 디렉터리가 있는 프로젝트 최상위 디렉터리)에서
`check` 명령어를 터미널에 입력


## **출력 형식**

```
======= print files ==========
해당 디렉토리 안의 디렉토리(exXX)에 있는 c 파일 출력
==============================
===== git uploaded files ====
깃에 파일이 잘 올라갔는지 및 파일명이 맞는지 확인하기 위한 깃에 정상적으로 올린 파일명 출력
=============================
==== norminette check ======
해당 디렉토리 안의 디렉토리(exXX)에 있는 c 파일들을 노미네이트로 돌린 결과 출력
============================
==== gcc check =============
해당 디렉토리 안의 디렉토리(exXX)에 있는 c 파일들을 gcc로 돌릴 시 나온 에러 결과 출력
	=>이 때 아무것도 출력되지 않는다면 모든 파일이 정상적으로 출력이 가능하다는 의미
	=>main이 포함된 파일이라면 정상적으로 처리되지 않습니다
```
