#include <raylib.h>
#include <iostream>

// Função que exibe o menu e retorna o estado do jogo (1 = Jogo Iniciado, 2 = Jogo Encerrado)
int Menu(int widthScreen, int heightScreen, int gameIsRunning) {
    

    int fontSize = 24;
    // Laço que continua enquanto o jogo não estiver rodando (gameIsRunning == 0)
    while (gameIsRunning == 0) {
        if (IsKeyPressed(KEY_ESCAPE)) {
            gameIsRunning = 3; // Atualiza gameIsRunning para encerrar
            return gameIsRunning;
        }
        // Verifica se o botão esquerdo do mouse foi pressionado
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            
            // Verifica se o clique do mouse foi na área do botão "PLAYER X CPU"
            if (GetMouseX() >= widthScreen / 2 - 165 && GetMouseX() <= widthScreen / 2 + 165 && 
                GetMouseY() >= heightScreen / 2 && GetMouseY() <= heightScreen / 2 + 70) {
                gameIsRunning = 1;  // Define que o jogo deve iniciar
                return gameIsRunning;  // Retorna 1 para indicar que o jogo vai começar
                
            // Verifica se o clique do mouse foi na área do botão "PLAYER X PLAYER"
            } else if (GetMouseX() >= widthScreen / 2 - 165 && GetMouseX() <= widthScreen / 2 + 165 && 
                GetMouseY() >= heightScreen / 2 - 120 && GetMouseY() <= heightScreen / 2 - 50) {
                gameIsRunning = 2;  // Define que o jogo deve iniciar
                return gameIsRunning;  // Retorna 1 para indicar que o jogo vai começar{
            
            
            
            } else if (GetMouseX() >= widthScreen / 2 - 165 && GetMouseX() <= widthScreen / 2 + 165 && 
                    GetMouseY() >= heightScreen / 1.5 && GetMouseY() <= heightScreen / 1.5 + 70) {
                gameIsRunning = 3;  // Define que o jogo deve encerrar
                return gameIsRunning;  // Retorna 2 para indicar que o jogo deve encerrar
            }
        }

        // Início do desenho da tela
        BeginDrawing();
        ClearBackground(BLACK);  // Limpa o fundo da tela e o pinta de preto

        // Desenha o botão "PLAY" como um retângulo branco
        DrawRectangle(widthScreen / 2 - 165, heightScreen / 3, 330, 70, WHITE);
        DrawText("PLAYER X PLAYER", widthScreen / 2 - MeasureText("PLAYER X PLAYER", fontSize) / 2, heightScreen / 3 + fontSize, fontSize, BLACK);  // Texto "PLAYER X PLAYER" no botão

        DrawRectangle(widthScreen / 2 - 165, heightScreen / 2, 330, 70, WHITE);
        DrawText("PLAYER X CPU", widthScreen / 2 - MeasureText("PLAYER X CPU", fontSize) / 2, heightScreen / 2 + fontSize, fontSize, BLACK);  // Texto "PLAYER X CPU" no botão

        // Desenha o botão "EXIT" como um retângulo branco
        DrawRectangle(widthScreen / 2 - 165, heightScreen/1.5 , 330, 70, WHITE);
        DrawText("EXIT", widthScreen / 2 - MeasureText("EXIT", fontSize) / 2, heightScreen / 1.5 + fontSize, fontSize, BLACK);  // Texto "EXIT" no botão

        EndDrawing();  // Fim do desenho da tela
    }

    // Retorna o valor de gameIsRunning caso o laço não tenha sido executado (segurança)
    return gameIsRunning;
}