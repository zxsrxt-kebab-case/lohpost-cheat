#include <d3d11.h>
#include <dxgi.h>
#include <iostream>
#include <Windows.h>
#include "deps/imgui/imgui.h"
#include "deps/imgui/impl/imgui_impl_dx11.h"
#include "deps/imgui/impl/imgui_impl_win32.h"
#include "deps/minhook/mh.h"
#include "src/hooks/dx_hook/dx_hook.hpp"
#include <vector>
#include "src/gui/gui.hpp"
#include "src/hooks/player_hook/playerhook.hpp"

void CreateConsole() {
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);
}



extern LRESULT ImGui_ImplWin32_WndProcHandler( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );

typedef HRESULT( __stdcall* Present ) ( IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags );
typedef LRESULT( CALLBACK* WNDPROC )( HWND, UINT, WPARAM, LPARAM );

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

void init_imgui( )
{
    ImGui::CreateContext( );
    ImGuiIO& io = ImGui::GetIO( );
    io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;

    io.Fonts->AddFontDefault( );

    ImGui_ImplWin32_Init( window );
    ImGui_ImplDX11_Init( pDevice, pContext );
}

LRESULT __stdcall WndProc( const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) {

    if ( true && ImGui_ImplWin32_WndProcHandler( hWnd, uMsg, wParam, lParam ) )
        return true;

    return CallWindowProc( oWndProc, hWnd, uMsg, wParam, lParam );
}



HRESULT __stdcall hkPresent( IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags )
{
    static bool init = false;
    if ( !init )
    {
        if ( SUCCEEDED( pSwapChain->GetDevice( __uuidof( ID3D11Device ), ( void** ) &pDevice ) ) )
        {
            pDevice->GetImmediateContext( &pContext );
            DXGI_SWAP_CHAIN_DESC sd;
            pSwapChain->GetDesc( &sd );
            window = sd.OutputWindow;
            ID3D11Texture2D* pBackBuffer;
            pSwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), ( LPVOID* ) &pBackBuffer );
            pDevice->CreateRenderTargetView( pBackBuffer, NULL, &mainRenderTargetView );
            pBackBuffer->Release( );
            oWndProc = ( WNDPROC ) SetWindowLongPtr( window, GWLP_WNDPROC, ( LONG_PTR ) WndProc );
            init_imgui( );
            init = true;
        }

        else
            return oPresent( pSwapChain, SyncInterval, Flags );
    }


    ImGui_ImplDX11_NewFrame( );
    ImGui_ImplWin32_NewFrame( );
    ImGui::NewFrame( );

    gui::run();

    ImGui::Render( );

    pContext->OMSetRenderTargets( 1, &mainRenderTargetView, NULL );
    ImGui_ImplDX11_RenderDrawData( ImGui::GetDrawData( ) );
    return oPresent( pSwapChain, SyncInterval, Flags );
}




DWORD WINAPI MainThread( LPVOID lpReserved )
{
    bool init_hook = false;
    do
    {
        if ( dx_hook::init( ) == dx_hook::status::done )
        {
            dx_hook::hook( 8, ( void** ) &oPresent, (void*) hkPresent );

            MH_EnableHook( MH_ALL_HOOKS );

            player_hook::hook();

            init_hook = true;
        }
    } while ( !init_hook );
    return TRUE;
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpvReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        CreateConsole();
        DisableThreadLibraryCalls( hModule );
        CreateThread( nullptr, 0, MainThread, hModule, 0, nullptr );
    }
    return TRUE;
}