#include <conio.h>
#include <windows.h>


// 전역 변수
HINSTANCE hInst;
HWND hWnd;
HWND hButtonBono, hButtonRyan, hButtonBox, hButtonCircle, hButtonCube;

enum ShapeType { Bono, Ryan, NONE, BOX, CIRCLE, Cube, CBono };
ShapeType currentShape = NONE;

POINT ptStart, ptEnd;
bool isDragging = false;



void DrawBonobono(HDC hdc, int x, int y) {
    HBRUSH hBrush = CreateSolidBrush(RGB(127, 200, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x - 50, y - 50, x + 50, y + 50);

    HBRUSH hMouthBrush = CreateSolidBrush(RGB(255, 150, 255));
    SelectObject(hdc, hMouthBrush);
    Ellipse(hdc, x - 10, y + 5, x + 10, y + 30);

    HBRUSH hMouthBrush2 = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hMouthBrush2);
    Ellipse(hdc, x - 1, y - 5, x + 23, y + 15);
    Ellipse(hdc, x - 23, y - 5, x + 1, y + 15);

    HBRUSH hNoseBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hNoseBrush);
    Ellipse(hdc, x - 7, y - 10, x + 7, y + 5);
    MoveToEx(hdc, x + 15, y, NULL);
    LineTo(hdc, x + 35, y - 5);
    MoveToEx(hdc, x + 15, y + 5, NULL);
    LineTo(hdc, x + 37, y + 8);
    MoveToEx(hdc, x - 15, y, NULL);
    LineTo(hdc, x - 35, y - 5);
    MoveToEx(hdc, x - 15, y + 5, NULL);
    LineTo(hdc, x - 37, y + 8);

    HBRUSH hEyeBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hEyeBrush);
    Ellipse(hdc, x - 40, y - 10, x - 30, y - 20);
    Ellipse(hdc, x + 40, y - 10, x + 30, y - 20);

    HBRUSH hEyeBallBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hEyeBallBrush);
    Ellipse(hdc, x - 38, y - 13, x - 32, y - 18);
    Ellipse(hdc, x + 38, y - 13, x + 32, y - 18);



}
void DrawCloseBonobono(HDC hdc, int x, int y) {


    HBRUSH hBrush = CreateSolidBrush(RGB(127, 200, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x - 50, y - 50, x + 50, y + 50);

    HBRUSH hMouthBrush = CreateSolidBrush(RGB(255, 150, 255));
    SelectObject(hdc, hMouthBrush);
    Ellipse(hdc, x - 10, y + 5, x + 10, y + 30);

    HBRUSH hMouthBrush2 = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hMouthBrush2);
    Ellipse(hdc, x - 1, y - 5, x + 23, y + 15);
    Ellipse(hdc, x - 23, y - 5, x + 1, y + 15);

    HBRUSH hNoseBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hNoseBrush);
    Ellipse(hdc, x - 7, y - 10, x + 7, y + 5);
    MoveToEx(hdc, x + 15, y, NULL);
    LineTo(hdc, x + 35, y - 5);
    MoveToEx(hdc, x + 15, y + 5, NULL);
    LineTo(hdc, x + 37, y + 8);
    MoveToEx(hdc, x - 15, y, NULL);
    LineTo(hdc, x - 35, y - 5);
    MoveToEx(hdc, x - 15, y + 5, NULL);
    LineTo(hdc, x - 37, y + 8);

    HBRUSH hCloseBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hCloseBrush);
    MoveToEx(hdc, x - 35, y - 30, NULL);
    LineTo(hdc, x - 20, y - 20);
    MoveToEx(hdc, x - 40, y - 10, NULL);
    LineTo(hdc, x - 20, y - 20);
    MoveToEx(hdc, x + 35, y - 30, NULL);
    LineTo(hdc, x + 20, y - 20);
    MoveToEx(hdc, x + 40, y - 10, NULL);
    LineTo(hdc, x + 20, y - 20);

}
void DrawRyan(HDC hdc, int sx, int sy, int ex, int ey) {

    POINT start = { 0 };
    POINT end = { 0 };

    start.x = min(sx, ex);
    start.y = min(sy, ey);
    end.x = max(sx, ex);
    end.y = max(sy, ey);

    RECT rf = { start.x, start.y, end.x, end.y };

    int width = abs(start.x - end.x);
    int height = abs(start.y - end.y);
    int centerX = width / 2;
    int centerY = height / 2;
    POINT centerPoint = { start.x + centerX, start.y + centerY };

    HBRUSH RskinBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, RskinBrush);

    // 귀부분 좌상에서 정상
    RECT Lear = { start.x , start.y, start.x + width / 3, start.y + height / 3 };
    RECT Rear = { end.x , start.y, end.x - width / 3, start.y + height / 3 };

    // 왼귀
    Ellipse(hdc, Lear.left, Lear.top, Lear.right, Lear.bottom);
    // 오른귀
    Ellipse(hdc, Rear.left, Rear.top, Rear.right, Rear.bottom);
    // 얼굴
    Ellipse(hdc, rf.left, rf.top, rf.right, rf.bottom);

    POINT Leye = { start.x + centerX / 2, start.y + (centerY / 6 * 5) };
    POINT Reye = { end.x - centerX / 2, start.y + (centerY / 6 * 5) };
    RECT Leyes = { Leye.x, Leye.y, Leye.x + width / 20, Leye.y + height / 20 };
    RECT Reyes = { Reye.x, Reye.y, Reye.x - width / 20, Reye.y + height / 20 };

    // 눈
    HBRUSH Blacks = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, Blacks);
    Ellipse(hdc, Leyes.left, Leyes.top, Leyes.right, Leyes.bottom);
    Ellipse(hdc, Reyes.left, Reyes.top, Reyes.right, Reyes.bottom);

    // 눈썹3가닥
    MoveToEx(hdc, start.x + centerX / 4, start.y + centerY / 3 * 2, NULL);
    LineTo(hdc, start.x + (centerX / 4 * 3), start.y + (centerY / 3 * 2));
    MoveToEx(hdc, start.x + centerX / 4, start.y + centerY / 3 * 2 + 2, NULL);
    LineTo(hdc, start.x + (centerX / 4 * 3), start.y + (centerY / 3 * 2) + 2);
    MoveToEx(hdc, start.x + centerX / 4, start.y + centerY / 3 * 2 + 4, NULL);
    LineTo(hdc, start.x + (centerX / 4 * 3), start.y + (centerY / 3 * 2) + 4);

    MoveToEx(hdc, end.x - centerX / 4, start.y + centerY / 3 * 2, NULL);
    LineTo(hdc, end.x - (centerX / 4 * 3), start.y + (centerY / 3 * 2));
    MoveToEx(hdc, end.x - centerX / 4, start.y + centerY / 3 * 2 + 2, NULL);
    LineTo(hdc, end.x - (centerX / 4 * 3), start.y + (centerY / 3 * 2) + 2);
    MoveToEx(hdc, end.x - centerX / 4, start.y + centerY / 3 * 2 + 4, NULL);
    LineTo(hdc, end.x - (centerX / 4 * 3), start.y + (centerY / 3 * 2) + 4);

    // 코
    RECT Lnose = { centerPoint.x - centerX / 5, centerPoint.y, centerPoint.x, centerPoint.y + centerY / 5 };
    RECT Rnose = { centerPoint.x, centerPoint.y, centerPoint.x + centerX / 5, centerPoint.y + centerY / 5 };
    HBRUSH Whites = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, Whites);
    Ellipse(hdc, Lnose.left, Lnose.top, Lnose.right, Lnose.bottom);
    Ellipse(hdc, Rnose.left, Rnose.top, Rnose.right, Rnose.bottom);



    /*
    안움직이는 라이언
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + 10, y - 60, x + 60, y - 10);
    Ellipse(hdc, x - 10, y - 60, x - 60, y -10);
    Ellipse(hdc, x - 50, y - 50, x + 50, y + 50);

    HBRUSH hMouthBrush2 = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hMouthBrush2);
    Ellipse(hdc, x - 1, y + 5, x + 20, y + 25);
    Ellipse(hdc, x - 20, y + 5, x + 1, y + 25);

    HBRUSH hNoseBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hNoseBrush);
    Ellipse(hdc, x - 6, y+3, x + 6, y + 15);

    HBRUSH hEyeBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hEyeBrush);
    Ellipse(hdc, x - 25, y, x - 15, y - 10);
    Ellipse(hdc, x + 25, y, x + 15, y - 10);
    MoveToEx(hdc, x - 40, y - 20, NULL);
    LineTo(hdc, x - 10, y - 20);
    MoveToEx(hdc, x - 40, y - 21, NULL);
    LineTo(hdc, x - 10, y - 21);
    MoveToEx(hdc, x - 40, y - 22, NULL);
    LineTo(hdc, x - 10, y - 22);
    MoveToEx(hdc, x - 40, y - 23, NULL);
    LineTo(hdc, x - 10, y - 23);
    MoveToEx(hdc, x + 40, y - 20, NULL);
    LineTo(hdc, x + 10, y - 20);
    MoveToEx(hdc, x + 40, y - 21, NULL);
    LineTo(hdc, x + 10, y - 21);
    MoveToEx(hdc, x + 40, y - 22, NULL);
    LineTo(hdc, x + 10, y - 22);
    MoveToEx(hdc, x + 40, y - 23, NULL);
    LineTo(hdc, x + 10, y - 23);*/



}



// 모양 그리기 함수
void DrawShape(HWND hWnd, HDC hdc) {
    HBRUSH hBrush = CreateSolidBrush(RGB(127, 200, 255)); // 빨간색
    SelectObject(hdc, hBrush);


    if (!isDragging) {
        switch (currentShape) {
        case BOX: {
            Rectangle(hdc, ptStart.x, ptStart.y, ptEnd.x, ptEnd.y);
            break;
        }
        case CIRCLE: {
            int radius = min(abs(ptEnd.x - ptStart.x), abs(ptEnd.y - ptStart.y)) / 2;
            Ellipse(hdc, ptStart.x - radius, ptStart.y - radius, ptStart.x + ptEnd.x - ptStart.x, ptStart.y + ptEnd.y - ptStart.y);
            break;
        }
        case Bono: {
            DrawBonobono(hdc, ptStart.x + (ptStart.y - ptStart.x) / 2, ptStart.y + (ptStart.y - ptStart.x) / 2);
            break;
        }
        case CBono: {
            DrawCloseBonobono(hdc, ptStart.x + (ptStart.y - ptStart.x) / 2, ptStart.y + (ptStart.y - ptStart.x) / 2);
            break;
        }
        case Ryan: {
            DrawRyan(hdc, ptStart.x, ptStart.y, ptEnd.x, ptEnd.y);
            break;
        }



        default:
            break;
        }
        if (hBrush) {
            DeleteObject(hBrush);
        }
    }

    DeleteObject(hBrush);
}



// 윈도우 프로시저
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_KEYDOWN:
        // 스페이스바가 눌렸을 때
        if (wParam == VK_SPACE && currentShape == Bono) {
            currentShape = CBono;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;

    case WM_KEYUP:
        // 스페이스바가 눌렸을 때
        if (wParam == VK_SPACE && currentShape == CBono) {
            currentShape = Bono;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case 1:
            currentShape = BOX;
            break;
        case 2:
            currentShape = CIRCLE;
            break;
        case 3:
            currentShape = Bono;
            SetFocus(hWnd);
            break;
        case 4:
            currentShape = Ryan;
            break;

        case 5:
            currentShape = NONE;
            break;
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;


    case WM_LBUTTONDOWN:
        ptStart.x = LOWORD(lParam);
        ptStart.y = HIWORD(lParam);
        ptEnd = ptStart;
        isDragging = true;
        break;


    case WM_LBUTTONUP:
        if (isDragging) {
            ptEnd.x = LOWORD(lParam);
            ptEnd.y = HIWORD(lParam);
            isDragging = false;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;

    case WM_MOUSEMOVE:
        if (isDragging) {
            ptEnd.x = LOWORD(lParam);
            ptEnd.y = HIWORD(lParam);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    case WM_ERASEBKGND:
    {
        HDC hdc = (HDC)wParam;
        RECT rc;
        GetClientRect(hWnd, &rc);
        HBRUSH hBackgroundBrush = CreateSolidBrush(RGB(255, 240, 200));
        FillRect(hdc, &rc, hBackgroundBrush);
        DeleteObject(hBackgroundBrush);
        return (LRESULT)1;
    }
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        DrawShape(hWnd, hdc);
        EndPaint(hWnd, &ps);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 윈도우 초기화 함수
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
    hInst = hInstance;

    hWnd = CreateWindow(
        L"ButtonWindowClass", L"곰돌이", WS_OVERLAPPEDWINDOW & ~WS_SIZEBOX,
        800, 480, 920, 480, NULL, NULL, hInstance, NULL);

    if (!hWnd) {
        return FALSE;
    }

    hButtonBox = CreateWindow(
        L"BUTTON", L"Box", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        16, 16, 160, 64, hWnd, (HMENU)1, hInstance, NULL);

    hButtonCircle = CreateWindow(
        L"BUTTON", L"Circle", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        192, 16, 160, 64, hWnd, (HMENU)2, hInstance, NULL);

    hButtonBono = CreateWindow(
        L"BUTTON", L"BonoBono", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        368, 16, 160, 64, hWnd, (HMENU)3, hInstance, NULL);

    hButtonRyan = CreateWindow(
        L"BUTTON", L"Ryan", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        544, 16, 160, 64, hWnd, (HMENU)4, hInstance, NULL);

    hButtonCube = CreateWindow(
        L"BUTTON", L"Cube", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        720, 16, 160, 64, hWnd, (HMENU)5, hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}



// 프로그램 진입점
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wcex;
    wcex.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_CROSS);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = L"ButtonWindowClass";
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);




    if (!RegisterClassEx(&wcex)) {
        return 1;
    }

    if (!InitInstance(hInstance, nCmdShow)) {
        return 1;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}



