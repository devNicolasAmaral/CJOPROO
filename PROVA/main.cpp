#include <cstdio>
#include <raylib.h>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Player {
private:
    Vector2 position;
    float radius;
    float speed;
    Texture2D texture;
    bool facingRight;

public:
    Player(float x, float y, float radius, float speed, const char* texturePath)
    : position({x, y}), radius(radius), speed(speed), facingRight(true) {
        texture = LoadTexture(texturePath);
        if (texture.id == 0) {  // Verifica se a textura foi carregada com sucesso
            printf("Falha ao carregar a textura do jogador.\n");
        }
    }

    ~Player() {
        UnloadTexture(texture);  // Garante que a textura do jogador seja descarregada corretamente
    }

    void Update() {
        Vector2 direction = {0.0f, 0.0f};
        if (IsKeyDown(KEY_W)) direction.y -= 1.0f;
        if (IsKeyDown(KEY_S)) direction.y += 1.0f;
        if (IsKeyDown(KEY_A)) {
            direction.x -= 1.0f;
            facingRight = false;
        }
        if (IsKeyDown(KEY_D)) {
            direction.x += 1.0f;
            facingRight = true;
        }

        float length = sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length > 0) {
            direction.x /= length;
            direction.y /= length;
        }

        position.x += direction.x * speed * GetFrameTime();
        position.y += direction.y * speed * GetFrameTime();
    }

    void Draw() const {
        Rectangle source = {0.0f, 0.0f, (!facingRight ? (float)texture.width : -(float)texture.width), (float)texture.height};
        Rectangle dest = {position.x, position.y, (float)texture.width, (float)texture.height};
        Vector2 origin = {(float)texture.width / 2, (float)texture.height / 2};
        DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
    }

    Vector2 GetPosition() const { return position; }
    float GetRadius() const { return radius; }
};

class Collectible {
private:
    Vector2 position;
    Vector2 velocity;
    float radius;
    bool active;
    Texture2D texture;  // Certifique-se de carregar a textura específica para o item
    float spawnTime;

public:
    Collectible(float x, float y, float radius, const char* texturePath, Vector2 direction)
: position({x, y}), velocity(direction), radius(radius), active(true), spawnTime(GetTime()) {
    texture = LoadTexture(texturePath);
    if (texture.id == 0) {
        printf("Falha ao carregar a textura do item: %s\n", texturePath);  // Print para depuração
    } else {
        printf("Textura carregada com sucesso para o item: %s\n", texturePath);  // Print para depuração
    }
}

    void Update() {
        if (active) {
            position.x += velocity.x * GetFrameTime();
            position.y += velocity.y * GetFrameTime();

            // Verifica se o tempo de vida do item expirou (15 segundos)
            if (GetTime() - spawnTime >= 15.0f) {
                active = false;
            }
        }
    }

    void Draw() const {
        if (active) {
            DrawTexture(texture, position.x - texture.width / 2, position.y - texture.height / 2, WHITE);
        }
    }

    bool CheckCollision(const Player& player) {
        if (!active) return false;

        float distance = sqrt(pow(player.GetPosition().x - position.x, 2) +
                              pow(player.GetPosition().y - position.y, 2));
        if (distance <= player.GetRadius() + radius) {
            active = false;
            return true;
        }
        return false;
    }

    bool IsActive() const { return active; }
};

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Prova P2");
    SetTargetFPS(60);

    Player player(screenWidth / 2, screenHeight / 2, 20.0f, 200.0f, "img/player.png");

    std::vector<Collectible> collectibles;
    srand(time(0));

    int score = 0;
    float elapsedTime = 0.0f;
    float itemSpeed = 200.0f;

    while (!WindowShouldClose()) {
        elapsedTime += GetFrameTime();

        // Gera itens a cada 5 segundos
        if (elapsedTime >= 5.0f) {
            int numItems = rand() % 2 + 1;

            for (int i = 0; i < numItems; ++i) {
                float x, y;

                // Gera itens na área visível da tela
                x = rand() % 2 == 0 ? screenWidth + rand() % 100 : -rand() % 100;
                y = rand() % screenHeight;

                float dirX = screenWidth / 2 - x;
                float dirY = screenHeight / 2 - y;
                float length = sqrt(dirX * dirX + dirY * dirY);
                Vector2 direction = {dirX / length, dirY / length};

                direction.x *= itemSpeed;
                direction.y *= itemSpeed;

                collectibles.emplace_back(x, y, 10.0f, "img/score.png", direction);
            }

            elapsedTime = 0.0f;
        }

        player.Update();

        for (auto& collectible : collectibles) {
            collectible.Update();
            if (collectible.CheckCollision(player)) {
                score += 10;
            }
        }

        collectibles.erase(std::remove_if(collectibles.begin(), collectibles.end(),
            [](const Collectible& c) { return !c.IsActive(); }),
            collectibles.end());

        BeginDrawing();
        ClearBackground(BLACK);

        player.Draw();

        for (const auto& collectible : collectibles) {
            collectible.Draw();
        }

        DrawText(TextFormat("Score: %d", score), screenWidth - 150, 10, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
