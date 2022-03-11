#include "GameEngineWindow.h"
#include "GameEngineDebug.h"

//HWND hWnd � �����쿡 �������� ������� �� �������� �ڵ�
//UINT message �� �޼����� ������ ����
// WPARAM wParam 
//LPARAM lParam

int Xmove = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        return DefWindowProc(hWnd, message, wParam, lParam);
    case WM_SETFOCUS:
        return DefWindowProc(hWnd, message, wParam, lParam);
    case WM_DESTROY:
        GameEngineWindow::GetInst().off();
        return DefWindowProc(hWnd, message, wParam, lParam);
        //������ ȭ�鿡 ������ �׷����ٸ�
    case WM_PAINT: 
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        //��¿� �ʿ��� ������ ������ ������ ����ü
        Rectangle(hdc, 100, 100, 200, 200);
        EndPaint(hWnd, &ps);
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    case WM_MOUSEMOVE:
    {
        return DefWindowProc(hWnd, message, wParam, lParam);
        Rectangle(GameEngineWindow::GetInst().GETDC(), 100, 100, 200, 200);
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
{
}

GameEngineWindow::~GameEngineWindow()
{
}

void GameEngineWindow::off()
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

void GameEngineWindow::MessageLoop()
{
    MSG msg;
    while (WindowOn_)
    {
        if (GetMessage(&msg, nullptr, 0, 0))
        {
            DispatchMessage(&msg);
        }
    }
}