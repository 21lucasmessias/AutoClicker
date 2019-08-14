#include <stdio.h>
#include <windows.h>
#include <time.h>

void main(){
	ULONG_PTR seila; // Nao entendi o que isso faz, mas eh um parametro da funcao mouse_event
	POINT cursorPos; // Struct tipo Ponto com coordenadas x e y
	char KeyCode = 'Y';
	do{
		//------------------------------------ Executar auto click -----------------------------------------------------------
		if(GetKeyState(VK_CAPITAL)){//Essa funcao retorna 0 se a tecla (VK_CAPITAL)[Caps Lock] estiver desligada e 1 se ativado
			printf("Start\n");
			do{
				//--------------------------------------Coordenadas---------------------------------------------------------
				GetCursorPos(&cursorPos);//Recebe as coordenadas x e y de onde o mouse se encontra
				//-----------------------------------------------------------------------------------------------------------

				//---------------------------------------Mouse---------------------------------------------------------------
				mouse_event(MOUSEEVENTF_RIGHTDOWN, cursorPos.x, cursorPos.y, XBUTTON1, seila);//Pressiona o botao direito
				Sleep(50);//Espera uns milesimos n sei qnts pq sempre bugo com conversao xd, necessario pra n bugar o clique
				mouse_event(MOUSEEVENTF_RIGHTUP, cursorPos.x, cursorPos.y, XBUTTON1, seila);//Solta o botao direito
				Sleep(3000);//Espera 3 segundos, pra ter um delayzinho na abertura dos baus
				//-----------------------------------------------------------------------------------------------------------

				//--------------------------------------Teclado--------------------------------------------------------------
				keybd_event(VkKeyScan(KeyCode), 0x86, 0, 0);//0x86 = Y , Pressiona a tecla Y
				Sleep(50);//Espera pra n bugar a tecla
				keybd_event(VkKeyScan(KeyCode), 0x86, KEYEVENTF_KEYUP, 0);//Solta a tecla Y
				//-----------------------------------------------------------------------------------------------------------
				if(GetKeyState(VK_END)) break;//Verifica se o usuario n apertou END pra finalizar o programa durante o loop
			}while(GetKeyState(VK_CAPITAL));//Enqnt a pessoa nao desligar o (VK_CAPITAL)[Caps Lock] ele executa o autoclick
			printf("Stop");
		}
		//-----------------------------------------------------------------------------------------------------------
	}while(!GetKeyState(VK_END));//Verifica se o usuario apertou END pra finalizar o programa
}