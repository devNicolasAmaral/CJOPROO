#include <raylib.h>
#include <string>
#include <cmath>
#include "Menu.hpp"

Color Blue = Color{58, 124, 165, 255};
Color DarkBlue = Color{47, 102, 144, 255};
Color LightBlue = Color{129, 195, 215, 255};
Color Orange = Color{254, 127, 45, 255};

int playerScore = 0;
int player2Score = 0;
int cpuScore = 0;
int maxScore = 5; // Pontuação máxima para ganhar
bool isPaused = false;
int gameIsRunning = 0;

class Ball {
public:
    float x, y; // Coordenadas da bola na tela
    float speedIncrement = 0.08; // Taxa de incremento na velocidade ao longo do tempo
    float speedX, speedY; // Velocidades horizontal e vertical da bola
    int radius; // Raio da bola
    int frameCounter = 0; // Contador para controlar o incremento de velocidade

    // Desenha a bola na tela
    void Draw() { 
        DrawCircle(x, y, radius, Orange); 
    }

    void Update() {
        if (!isPaused) { 
            // Atualiza a posição da bola com base na velocidade
            x += speedX;
            y += speedY;
        }

        if (!isPaused) {
            frameCounter++;
            // Incrementa a velocidade da bola a cada 60 frames
            if (frameCounter >= 60) { 
                speedX += (speedX > 0 ? speedIncrement : -speedIncrement); // Ajusta direção
                speedY += (speedY > 0 ? speedIncrement : -speedIncrement); // Ajusta direção
                frameCounter = 0;
            }
        }

        // Detecta e inverte a direção ao colidir com bordas superior/inferior
        if (y + radius >= GetScreenHeight() || y - radius <= 0) {
            speedY *= -1; 
        }

        // Verifica colisão com as bordas laterais e pontuações
        if (x + radius * -2 >= GetScreenWidth()) { 
            // Incrementa a pontuação dependendo do modo de jogo
            if (gameIsRunning == 1) { 
                cpuScore++;
            } else if (gameIsRunning == 2) { 
                player2Score++;
            }
            resetBall(); // Reinicia a posição da bola
        }
        if (x - radius * -2 <= 0) { 
            playerScore++; // Incrementa a pontuação do jogador
            resetBall(); // Reinicia a posição da bola
        }
    }

    // Reinicia a bola no centro com velocidades aleatórias
    void resetBall() {
        y = GetScreenHeight() / 2;
        x = GetScreenWidth() / 2;
        int speedChoices[2] = {-1, 1}; // Escolhas para direção inicial
        speedX = 7.0f * speedChoices[GetRandomValue(0, 1)];
        speedY = 7.0f * speedChoices[GetRandomValue(0, 1)];
        frameCounter = 0; // Reseta o contador de frames
    }
};


class Paddle {
protected:
    void LimitMovement() {
        if (y <= 0) y = 0;
        if (y + height >= GetScreenHeight()) y = GetScreenHeight() - height;
    }
public:
    float x, y;
    float width, height;
    int speed;

    void Draw() {
        DrawRectangleRounded(Rectangle{x, y, width, height}, 0.3, 0, WHITE);
    }

    void Update() {
        if (!isPaused) {
            if (IsKeyDown(KEY_UP)) y -= speed;
            if (IsKeyDown(KEY_DOWN)) y += speed;
            LimitMovement();
        }
    }
};

class player2Paddle : public Paddle {
    public:
    
    void Update() {
        if (!isPaused) {
            if (IsKeyDown(KEY_W)) y -= speed;
            if (IsKeyDown(KEY_S)) y += speed;
            LimitMovement();
        }
    }
};

class CpuPaddle : public Paddle {
public:
    void Update(const Ball& ball) {

        float futureY = ball.y + ball.speedY * (std::abs(ball.speedX));
        float marginOfError = (rand() % 10 - 5);
        futureY += marginOfError;

        float distance = futureY - (y + height / 2);
        float adjustedSpeed = speed * (std::min(std::abs(distance) / 50.0f, 1.0f));

        if (!isPaused) {
            if (distance > 0) y += adjustedSpeed;
            else y -= adjustedSpeed;
        }
        LimitMovement();
    }
};

void CheckPaddleCollision(Ball &ball, Paddle &paddle) {
    if (ball.x + ball.radius >= paddle.x && ball.x - ball.radius <= paddle.x + paddle.width) {
        if (ball.y + ball.radius >= paddle.y && ball.y - ball.radius <= paddle.y + paddle.height) {
            ball.speedX *= -1;
            if (ball.x < GetScreenWidth() / 2) {
                ball.x = paddle.x + paddle.width + ball.radius;
            } else {
                ball.x = paddle.x - ball.radius;
            }
        }
    }
}

void Pause() {
    isPaused = !isPaused;
}

void DrawPauseMenu() {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Color{0, 0, 0, 180});
    DrawText("PAUSE", GetScreenWidth() / 2 - MeasureText("PAUSE", 40) / 2, GetScreenHeight() / 2 - 20, 40, WHITE);
}

void DrawGameOverScreen() {
    isPaused = true;

    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Color{0, 0, 0, 180});

    if (playerScore >= maxScore){
        DrawText("GAME OVER - PLAYER 1 WON!", GetScreenWidth() / 2 - MeasureText("GAME OVER - PLAYER 1 WON!", 40) / 2, GetScreenHeight() / 2 - 60, 40, WHITE);
    } else if (gameIsRunning == 1){
        if (cpuScore >= maxScore){
            DrawText("GAME OVER - CPU WON!", GetScreenWidth() / 2 - MeasureText("GAME OVER - CPU WON!", 40) / 2, GetScreenHeight() / 2 - 60, 40, WHITE);
        }
    } else if (player2Score >= maxScore){
            DrawText("GAME OVER - PLAYER 2 WON!", GetScreenWidth() / 2 - MeasureText("GAME OVER - PLAYER 2 WON!", 40) / 2, GetScreenHeight() / 2 - 60, 40, WHITE);
    }

    DrawText("Pressione 'R' para Reiniciar", GetScreenWidth() / 2 - MeasureText("Pressione 'R' para Reiniciar", 20) / 2, GetScreenHeight() / 2, 20, WHITE);
    DrawText("Pressione 'M' para Voltar ao Menu", GetScreenWidth() / 2 - MeasureText("Pressione 'M' para Voltar ao Menu", 20) / 2, GetScreenHeight() / 2 + 30, 20, WHITE);
    
}

void ResetGame() {
    playerScore = 0;
    cpuScore = 0;
    player2Score = 0;
    isPaused = false;
}

Ball ball;
Paddle player;
player2Paddle player2;
CpuPaddle cpu;

int main(void) {
    const int widthScreen = 1280;
    const int heightScreen = 720;

    InitWindow(widthScreen, heightScreen, "Pong");
    SetTargetFPS(60);


    ball.radius = 10;
    ball.x = widthScreen / 2;
    ball.y = heightScreen / 2;
    ball.speedX = 7.0;
    ball.speedY = 7.0;

    player.height = 120.0;
    player.width = 25;
    player.x = widthScreen - player.width - 20;
    player.y = heightScreen / 2 - player.height / 2;
    player.speed = 6.0;

    player2.height = 120.0;
    player2.width = 25;
    player2.x = 20;
    player2.y = heightScreen / 2 - cpu.height / 2;
    player2.speed = 6.0;

    cpu.height = 120.0;
    cpu.width = 25;
    cpu.x = 20;
    cpu.y = heightScreen / 2 - cpu.height / 2;
    cpu.speed = 6.0;


    while (WindowShouldClose() == false) {
        if (gameIsRunning == 0) {
            gameIsRunning = Menu(widthScreen, heightScreen, gameIsRunning);
        } else if (gameIsRunning == 1 || gameIsRunning == 2) {

            if (IsKeyPressed('P')) Pause();

            BeginDrawing();
            ball.Update();
            player.Update();
            if (gameIsRunning == 2){
                player2.Update();
            }
            if (gameIsRunning == 1){
                cpu.Update(ball);
            }
            CheckPaddleCollision(ball, player);
            CheckPaddleCollision(ball, player2);
            if (gameIsRunning == 1){
                CheckPaddleCollision(ball, cpu);
            }

            ClearBackground(DarkBlue);
            DrawRectangle(widthScreen / 2, 0, widthScreen / 2, heightScreen, Blue);
            DrawCircle(widthScreen / 2, heightScreen / 2, 150, LightBlue);
            DrawLine(widthScreen / 2, 0, widthScreen / 2, heightScreen, WHITE);
            ball.Draw();
            if (gameIsRunning == 1){
                cpu.Draw();
            }
            player.Draw();
            if (gameIsRunning == 2){
            player2.Draw();
            }
            if (gameIsRunning == 1){
                DrawText(TextFormat("%i", cpuScore), widthScreen / 4, 20, 80, WHITE);
            }
            if (gameIsRunning == 2){
                DrawText(TextFormat("%i", player2Score), widthScreen / 4, 20, 80, WHITE);
            }
            DrawText(TextFormat("%i", playerScore), 3 * widthScreen / 4, 20, 80, WHITE);
            DrawText("Pressione \"P\" para Pausar", 10, heightScreen - 90, 20, Color{255, 255, 255, 153});
            DrawText("Pressione \"M\" para voltar ao Menu", 10, heightScreen - 65, 20, Color{255, 255, 255, 153});
            DrawText("Pressione \"ESC\" para fechar o Jogo", 10, heightScreen - 40, 20, Color{255, 255, 255, 153});


            if ((isPaused) && (playerScore < maxScore && cpuScore < maxScore && player2Score < maxScore)) {
                DrawPauseMenu();
            }

            if (IsKeyPressed('M')) {
                gameIsRunning = 0;
                ResetGame();
            }

            // Checa se algum jogador alcançou a pontuação máxima
            if (playerScore >= maxScore || cpuScore >= maxScore || player2Score >= maxScore) {
                DrawGameOverScreen();
                if (IsKeyPressed('R')) {
                    ResetGame(); // Reinicia o jogo
                }
                if (IsKeyPressed('M')) {
                    gameIsRunning = 0; // Volta ao menu
                    ResetGame();
                }
            }

            EndDrawing();
        } else if (gameIsRunning == 3) {
            break;
        }
    }

    CloseWindow(); // Fecha a janela
    return 0;
}