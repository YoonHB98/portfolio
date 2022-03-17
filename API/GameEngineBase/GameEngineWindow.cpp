#include "GameEngineWindow.h"
#include "GameEngineDebug.h"

//HWND hWnd � �����쿡 �������� ������� �� �������� �ڵ�
//UINT message �� �޼����� ������ ����
// WPARAM wParam 
//LPARAM lParam

float XMove = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        GameEngineWindow::GetInst().Off();
        return DefWindowProc(hWnd, message, wParam, lParam);
        //������ ȭ�鿡 ������ �׷����ٸ�
    case WM_PAINT: 
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        //��¿� �ʿ��� ������ ������ ������ ����ü
        EndPaint(hWnd, &ps);
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    default:
        break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}

GameEngineWindow* GameEngineWindow::Inst_ = new GameEngineWindow();

GameEngineWindow::GameEngineWindow()
    : hInst_(nullptr)
    , hWnd_(nullptr)
    ,WindowOn_(true)
    , HDC_(nullptr)
{
}

GameEngineWindow::~GameEngineWindow()
{
    if (nullptr != HDC_)
    {
        ReleaseDC(hWnd_, HDC_);
        HDC_ = nullptr;

    }
    if (nullptr != hWnd_)
    {
        DestroyWindow(hWnd_);
        hWnd_ = nullptr;
    }
}

void GameEngineWindow::Off()
{
    WindowOn_ = false;
}

void GameEngineWindow::RegClass(HINSTANCE _hInst)
{
    WNDCLASSEXA wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = _hInst;
    wcex.hIcon = nullptr;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "GameEngineWindowClass";
    wcex.hIconSm = nullptr;

    RegisterClassExA(&wcex);

}

void GameEngineWindow::CreateGameWindow(HINSTANCE _hInst, const std::string& _Title)
{
    if (nullptr != hInst_)
    {//�ι� ȣ�� x 
        MsgBoxAssert("�����츦 2�� ������ �߽��ϴ�");
        return;
    }
    Title_ = _Title;
    hInst_ = _hInst;
    RegClass(_hInst);
   

    
    //(lpClassName, lpWindowName, dwStyle, x, y, \
 nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
    //�����츦 �����ϴ� �ڵ�
    hWnd_ = CreateWindowExA(0L, "GameEngineWindowClass", Title_.c_str(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, _hInst, nullptr);
    //ȭ�鿡 ���𰡸� �׸��� �ڵ�
    HDC_ = GetDC(hWnd_);

    
    if (!hWnd_)
    {
        return;
    }
    
    }

void GameEngineWindow::ShowGameWindow()
{
    if (nullptr == hWnd_)
    {
        MsgBoxAssert("���� �����찡 ��������� �ʾҽ��ϴ�. ȭ�鿡 ����� �� �����ϴ�.");
        return;
    }
    ShowWindow(hWnd_, SW_SHOW);
    UpdateWindow(hWnd_);
}

//�����Լ� �ΰ� �־��ָ� ���� ������
void GameEngineWindow::MessageLoop(void(*_InitLoopFunction)(), void(*_LoopFunction)())
{
    //������� �غ�Ǿ� �ְ�
    //������ �������� ���� �غ��Ұ� �ִٸ� �غ��Լ�  
    if (nullptr != _InitLoopFunction)
    {
        _InitLoopFunction();

    }
    MSG msg;
    while (WindowOn_)
    { 
     
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (nullptr == _LoopFunction)
        {
            continue;
        }
        _LoopFunction();
    }
}

void GameEngineWindow::SetWindowScaleAndPosition(float4 _Pos, float4 _Scale)
{
    //ix = int x
    RECT Rc = { 0, 0, _Scale.ix(), _Scale.iy() };

    AdjustWindowRect(&Rc, WS_OVERLAPPEDWINDOW, FALSE);

    Scale_ = _Scale;

    SetWindowPos(hWnd_, nullptr, _Pos.ix(), _Pos.iy(), Rc.right - Rc.left, Rc.bottom - Rc.top, SWP_NOZORDER);
}
