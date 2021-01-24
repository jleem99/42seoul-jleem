# Man 설명

<br/>

miniLibX - 학생들을 위한 간단한 윈도우 인터페이스 라이브러리
실행 - man /minilibx_mms_20200219/man/man3/[file name]

<br/>

# void *mlx_init();

<br/>

- 기본 설정(초기화)
- 소프트 웨어와 디스플레이를 연결
- 디스플레이에 대한 연결을 설정 하지 못하면 NULL 반환

<br/>

## Unix/Linux:

<br/>

- X-Window - Unix를 위한 네트워크 지향 그래픽 시스템
( 소프트웨어가 화면에 무언가를 그리거나 키보드 및 마우스 항목)

- X-Server - 화면,키보드 및 마우스 관리(디스플레이)

=> 도면 순서(software -> X-Server)와 키보드/마우스 이벤트(X-Server -> software)를
전송하려면 이 두 entities간에 네트워크 연결이 설정되어야 합니다.

<br/>

---------------------------------------------------------------------

<br/>

# 키보드 및 마우스 이벤트 처리(mlx_loop)

<br/>

## int mlx_loop(void *mlx_ptr);

<br/>

- 무한 루프 함수

<br/>

### - 기능 -

<br/>

- 키 누름
- 마우스 버튼을 누릅니다.
- window의 일부를 다시 그려야 한다.("expose" 이벤트, unix/linux X11 환경에서 다루는 일 but MacOS에서는 발생X)

<br/>

## mlx_key_hook(void *win_ptr, int();

<br/>

mlx_key_hook(void *win_ptr, int(*funct_ptr)(), void *param);

<br/>

- funct_ptr은 이벤트가 발생할 때 호출될 함수에 대한 포인터
- win_ptr 식별자에 의해 정의된 window로 한정됩니다. 

<br/>

## mlx_hook();

<br/>

mlx_hook(void *win_ptr, int(*funct_ptr)(), void *param);

<br/>

## mlx_loop_hook();

<br/>

mlx_loop_hook(void *mlx_ptr, int(*funct_ptr)(), void *param);

<br/>

- 이벤트가 생기지 않을 경우 인자로 받았던 함수 호출
- 이벤트 발생할 경우 아래 함수를 고정 파라미터로 호출

<br/>

###  - 함수 -

<br/>

- param은 mlx_*_hook 호출에 지정된 주소(MiniLibX에 의해서 사용, 수정X)
- expose_hook(void *param);
- key_hook(int keycode, void *param);
- mouse_hook(int button, int x, int y, void *param);
- loop_hook(void *param);

<br/>

###  - 키, 마우스 이벤트에 있어 추가적인 정보 전달 -

<br/>

- keycode: 어떤 키를 눌렀는지 알려준다.
- x,y: 창에서 눌린 마우스 클릭 좌표(X11 -> include파일 "keysymdef.h" 확인, MacOS 그냥 해보기)
- button: 어떤 마우스 버튼이 눌렸는 지 알려준다.

<br/>

```c

int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int mlx_loop_hook (void *mlx_ptr, int(*funct_ptr)(), void *param );

```

<br/>

- win_ptr: 특정된 window에만 적용
- funct_ptr: 이벤트 발생시 내가 호출하고 싶은 함수를 가리키는 함수 포인터
- param: 호출될 때마다 전달되고 필요한 매개 변수를 저장하는데 사용

<br/>

-------------------------------------------------------------------------------

<br/>

# 이미지 조작(mlx_new_image)

<br/>

void *mlx_new_image(void *mlx_ptr, int width, int height);

<br/>

- mlx_ptr: 연결 식별자
- 메모리에 새 이미지 생성
- 이미지 조작에 필요한 이미지 식별자를 return
- 에러 발생시 NULL return 
- 실패시 (void *)0 return

<br/>

## mlx_put_image_to_window();

<br/>

int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

<br/>

- 사용자는 이미지 내부를 그릴 수 있으며 언제든지 지정된 창 내에서 이미지를 dump하여 화면에 표시 할 수 있다.
- 디스플레이 연결, 사용할 창, 이미지에 관한 식별자 필요
- (x,y)좌표는 창에서 이미지를 배치할 위치

<br/>

## mlx_get_data_addr();

<br/>

char *mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );

<br/>

- 생성된 이미지에 대한 정보를 return하여 사용자가 이미지를 수정할 수 있도록 한다.
(이미지가 저장된 메모리 영역의 시작 주소 return)
- img_ptr: 사용할 이미지 저장
- bits_per_pixel: 픽셀 색상(이미지 깊이)을 나타내는데 필요한 bit 수
(첫번째 bit는 이미지의 첫번째 줄에 있는 첫 번째 픽셀의 색상
두번째 그룹은 첫 번째 줄의 두번째 픽셀 나타낸다.)
- size_line: 메모리에 이미지의 한 줄을 저장하는 데 사용되는 byte 수
(주소를 추가하여 두번째 줄의 시작을 가져온다.)
- endian: 이미지의 픽섹 생상을 little endian(endian == 0), big endian(endian == 1)으로 저장해야 하는지 알려준다.
(MacOS X. 클라이언트와 그래픽 framework가 동일한 endian을 가진다.)

<br/>

## mlx_get_color_value();

<br/>

unsigned int mlx_get_color_value ( void *mlx_ptr, int color );

<br/>

- 이미지 내부에 색상 저장
- 디스플레이에 따라 pixel 색상을 저장하는데 사용되는 bit 수 변경될 수 있다.
- 사용자는 일반적으로 각 구성 요소에 1 byte를 사용하여 RGB 모드에서 색상을 나타낸다.(mlx_pixel_put 참고)
=> 영상의 bits_per_pixel 요구 사항에 맞게 변환되어야 하면 디스플레이에서 색상을 이해해야 한다.

<br/>

- 표준 RGB 생상 매개변수를 사용
- bits_per_pixel의 최하위 bit는 이미지에 저장 될 수 있다.
- 변환이 필요하지 않는 경우(24,32 bit 깊이)에는 이 것을 사용하지 않아도 된다.
- 최하위 bit의 위치는 local 컴퓨터의 endian에 따라 다르다.
- 이미지의 endian이 로컬 endian과 다른 경우(X11 네트워크 환경에서만 발생) 이 값을 사용하기 전에 변환해야 한다.

<br/>

## XPM image, PNG image 

<br/>

```c

void * mlx_xpm_to_image ( void *mlx_ptr, char **xpm_data, int *width, int *height );
void * mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );
void * mlx_png_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );

```

<br/>

- 새 이미지 생성
- 함수에 따라 각각 xpm_data, filename이 지정
- MinilibX는 xpm, png를 다룰 때, 표준 xpm, png 라이브러리를 사용하지 않는다.
- 모든 type의 xpm, png 이미지를 읽지 못한다. but transparency(투명성)는 제어 된다.
- 에러 발생시 NULL return
- 이미지 식별자 주소 return

<br/>

## mlx_destroy_image();

<br/>

int mlx_destroy_image ( void *mlx_ptr, void *img_ptr );
- 주어진 이미지(img_ptr)를 삭제 한다.

<br/>

--------------------------------------------------------------------------

<br/>

# 창 관리(mlx_new_window)

<br/>

## void *mlx_new_window ();

<br/>

void *mlx_new_window (void *mlx_ptr, int size_x, int size_y, char *title);

<br/>

- 새 window을 스크린에 띄운다.
- size_x, size_y: window size
- title: window title bar에 표시
- mlx_ptr: mlx_init이 반환한 연결 식별자
- 다른 MinilibX 호출에서 사용할 수 있는 window 식별자를 return
(MinilibX는 n개의 각기 다른 window를 제어 할 수 있다.)
- 창 생성 실패시 NULL return((void*)0 return) 

<br/>

## int mlx_clear_window ();

<br/>

int mlx_clear_window (void *mlx_ptr, void *win_ptr);

<br/>

- 지정된 window를 지우고(검정색) 끈다.
- mlx_ptr: screen(화면) 연결 실별자
- win_ptr: window(창) 식별자

<br/>

## int mlx_destroy_window ();

<br/>

int mlx_destroy_window (void *mlx_ptr, void *win_ptr);

<br/>

- 지정된 window를 끈다.
- mlx_ptr: screen(화면) 연결 실별자
- win_ptr: window(창) 식별자

<br/>

# 창 내부 그리기(mlx_pixel_put)

<br/>

## int mlx_pixel_put ();

<br/>

int mlx_pixel_put (void *mlx_ptr, void *win_ptr, int x, int y, int color);

<br/>

- (x,y)좌표와 지정된 색상을 사용하여 win_ptr(window)에 그린다.
- (0,0): 좌측 상단
- mlx_ptr: 연결 식별자
- window 밖의 모든 디스플레이 삭제 => mlx_pixel_put 속도 느려진다.

<br/>

## int mlx_string_put  (); 

<br/>

int mlx_string_put  (void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

<br/>

- int mlx_pixel_put과 매개변수 의미는 동일 but 지정된 문자열이 (x,y)로 표시
- window 밖의 모든 디스플레이 삭제 => mlx_pixel_put 속도 느려진다.

<br/>

##  색 관리

<br/>

- color 매개변수는 int형 이다.
- 모든 표시 가능 색상은 red, green, blue의 3가지 기본 색상으로 나눌 수 있다.
- [0-255] 범위의 세가지 관련 값은 각 색상이 혼합되어 원래 색상을 생성하는 양을 나타낸다.

<br/>

| 0 | R | G | B |   각 [0-255] 범위의 color integer로 채워진다.
+---+---+---+---+

<br/>

### - 주의 -

<br/>

- int를 채울 때 endian 문제 발생하지 않도록 해야 한다.
- "blue" byte가 LSB(최하위 bit, Least significant bit)이다
- 하드웨어 기능에 따라 MSB(최상위 bit, Most significant bit)는 transparency(투명도)를 처리 할 수 있다.
- OpenGL 클래식과는 반대로 opacity(불투명도)를 나타내지 않는다.

<br/>