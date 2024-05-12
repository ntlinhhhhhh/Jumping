#include <SDL.h>
#include <SDL_image.h>
#include<SDL_ttf.h>
#include <iostream>
#include<vector>
#include<cstdlib>
#include<cstdlib>
#include<string>
#include<SDL_mixer.h>
#include<fstream>


// Khai báo các biến toàn cục
SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;
SDL_Renderer* gRenderer1 = nullptr;
SDL_Texture* gBackgroundTexture = nullptr;
SDL_Texture* gCharacterTexture = nullptr;
SDL_Texture* gGroundTexture = nullptr;
SDL_Texture* gSkyTexture = nullptr;
SDL_Texture* gObstacle1 = nullptr;
SDL_Texture* gObstacle2 = nullptr;
SDL_Texture* gObstacle3 = nullptr;
SDL_Texture* gObstacle4 = nullptr;
SDL_Texture* gObstacle5 = nullptr;
SDL_Texture* gRain1 = nullptr;
SDL_Texture* gRain2 = nullptr;
SDL_Texture* gRain3 = nullptr;
SDL_Texture* gLoading = nullptr;
SDL_Texture* gLoading1 = nullptr;
SDL_Texture* gMenu = nullptr;
SDL_Texture* gMenu1 = nullptr;
SDL_Texture* gMouse = nullptr;
SDL_Texture* gGameover = nullptr;
SDL_Texture* gscore = nullptr;
SDL_Texture* ghighscore = nullptr;
SDL_Texture* gOption = nullptr;
SDL_Texture* gScore = nullptr;
SDL_Texture* gHighScore = nullptr;
SDL_Texture* gPause = nullptr;
SDL_Event E_vent;

//int distanse[5];

int gWindowWidth = 1200; // chieu rong cua cua so
int gWindowHeight = 600; // chieu cao cua cua so
int gCharacterWidth = 64; // chieu rong cua nhan vat
int gCharacterHeight = 64; // chieu cai cua nhan vat
int gCharacterX = 100;  // vi tri cua nhan vat
int gCharacterY = 440;  // vi tri cua vat
int gGroundHeight = 96; // chieu cao cua dat
int groundOffset = 0; // bien luu vi tri cua dat
int gSkyHeight = 311; // bien luu chieu cao cua bau troi
// Khai báo biến lưu vị trí hiện tại của mặt đất và mây
int groundPosX1 = 0;
int groundPosX2 = gWindowWidth;
int skyPosX1 = 0;
int skyPosX2 = gWindowWidth;
int LoadingWidth = 40;
int LoadingHeigth = 40;
int currentRes = 550;
int totalRes = 400;
int xScore = 270;
int yScore = 3;



// kich thuoc vat can
int ObstacleX1 = 54;
int ObstacleY1 = 52;
int ObstacleX2 = 38;
int ObstacleY2 = 38;
int ObstacleX3 = 32;
int ObstacleY3 = 64;
int ObstacleX4 = 64;
int ObstacleY4 = 64;
int ObstacleX5 = 64;
int ObstacleY5 = 64;
int LoadingX = 420;
int LoadingY = 273;
int loadcurrent = 0;
int LoadingXend = 1110;
int x_rain = 0;
int y_rain = 0;

int ObstacleStartX = 1200; // vi tri bat dau cua vat can
int ObstacleStartY = 440;
int ObstacleStartX1 = 1200; // vi tri bat dau cua vat can
int ObstacleStartY1 = 440;
int ObstacleStartX2 = 1500; // vi tri bat dau cua vat can
int ObstacleStartY2 = 440;
int obstacleNumber = 5; // so luong obstacle
int obstacleSpeed = 5; // toc do di chuyen cua stacle;
int loadedPercentage = 0;
int score = 0;
int high;
Uint32 starttime = 0;
Uint32 endtime = 0;
float speedscore = 1000.0f;

//định nghĩa hàm nhảy
const float Jump_Height = 100.0f; // chiều cao tối đa character nhảy là 100px
const float Jump_Speed = 400.0f; // vận tốc nhảy của nhân vật là 200px/s
bool isJumping = false; // trạng thái hiện tại của nhân vật
bool ismoveRight = false;  // trang thai cua vat tho truc x
bool ismoveLeft = false;  // trang thai cua vat tho truc x
float jumpStartY = 0.0f; // vị trí ban đầu khi bắt đầu nhảy
float jumpStartX = 0.0f; // vị trí ban đầu khi bắt đầu nhảy
float obstacleAngle = 0.0f; // vị trí ban đầu khi vật bắt đầu nhảy
bool gameover = false;


int textWidth;
int textHeight;

int random, random1;
// ham loading
void loadingimage();
bool loadingImage();
void renderLoading();

//void calcuLoaded(int currentRes, int totalRes); // sô luonf da tai, so luong ccan tai
//void renderLoadingBar();

std::vector<int> Loading1Pos;

//ham menu
bool menuImage();
void renderMenu();
bool loadmouse();
void renderMouse(int x, int y);
void Menu();

// gameover
bool Gameover();
void renderGameover();
void OverGame();



// Hàm tải texture từ file ảnh
SDL_Texture* loadTexture(const std::string& path);

// Hàm khởi tạo SDL và cửa sổ
bool init();

// Hàm load và hiển thị ảnh nền
bool loadBackground();

// ham load background
void renderBackground();

// Hàm cập nhật cửa sổ
void updateWindowSize(int width, int height);

// Hàm hiển thị ảnh nền
void render();

// Hàm cleanup và thoát chương trình
void close();

// load anh nhan vat
bool loadCharacter();

// hien thi nhan vat
void renderCharacter(int x, int y);

//hàm cập nhạt vị trí của nhân vật
void updateCharacterPosition(int deltaX, int DeltaY);

//ham xu ly su kien ban phim de nhan vat di chuyen
void handleKeyPress(SDL_Keycode key);


//ham xu ly nhay
void jump();

// hàm nhảy của nhân vật
void jumpCharacter(float deltaTime, int& gCharacter);

//ham di xuong
void fallCharacter(float deltaTime, int previousCharacterY, int& gCharacterY);


//dat cua game

// load anh nen dat
bool loadGround();

// in anh len man hinh
void renderGround();

// ham load anh bau troi
bool loadSky();

// ham in anh bau troi
void renderSky();

// ham cap nhat vi tri cua mat dat va may
void updateGroundandSky(); // cap naht vi tri cua mat dat va may khi di chuyen

// load anh chuong ngai vat
bool loadobstacle();
void renderObstacle();

//load anh option
bool option();
void renderoption();



// load diem khi choi
bool loadscore();
void renderscore();
void updatescore();



// ham cho vat di sang phai
void moveRightCharacter(float deltaTime, int& gCharacterX);
void moveRight();
void moveLeft();
void moveLeftCharacter(float deltaTime, int& gCharacterX);

// ham check xu ly cham
bool checkCollision(int characterX, int characterY, int characterWidth, int characterHeight, int obstacleX, int obstacleY, int obstacleWidth, int obstacleHeight);

SDL_Texture* loadfont(const std::string& path, int fontSize, std::string write);
bool Loadscore(int size, std::string path);
bool Loadhighscore(int size, std::string path);
void renderscore(int x, int y, int size, std::string path);
void renderhighscore(int x, int y, int size, std::string path);

//ham dung game
void pauseGame();

// ham load chuong ngai vat mua
bool rain();
void renderrain();


// xu ly am thanh (x=chua su ly duoc)
bool initializeSDL();

// Hàm load âm thanh từ tệp wav
Mix_Chunk* loadSound(const std::string& filename);

// Hàm phát âm thanh
void playSound(Mix_Chunk* sound);

// Hàm giải phóng bộ nhớ âm thanh
void cleanupSound(Mix_Chunk* sound);

void mainsound();


// uppdate diem
void updatehighscore();

// ham xu ly dung load anh continue len background
bool loadpause();
void renderpause();


// load du lieu
void loaddata();

// hàm điều khiển chương trinh
void control();



// hàm main của chương trinh
int main(int argc, char* argv[]) {
    //ham dk ctrinh4
    std::ifstream file("highscore.txt");
    if (file.is_open())
    {
        file >> high;

        std::cout << high;
    }

    loaddata();
    
    control();

    return 0;
}

// load option
bool option()
{
    gOption = loadTexture("option.png");
    if (gOption == nullptr)
    {
        std::cout << "Fail to load image option!\n";
        return false;
    }
    return true;
}
void renderoption()
{
    if (!option())
    {
        std::cout << "Faile to load option image!\n";
        return;
    }

    SDL_Rect option = { 1140, 10, 48, 48 };
    SDL_RenderCopy(gRenderer, gOption, NULL, &option);
}


// xu ly am thanh
bool initializeSDL() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
    }

    return true;
}

// Hàm load âm thanh từ tệp wav
Mix_Chunk* loadSound(const std::string& filename) {
    Mix_Chunk* sound = Mix_LoadWAV(filename.c_str());
    if (sound == nullptr) {
        std::cerr << "Failed to load sound effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    return sound;
}

// Hàm phát âm thanh
void playSound(Mix_Chunk* sound) {
    Mix_PlayChannel(-1, sound, 0);
    while (Mix_Playing(-1) != 0);
}

// Hàm giải phóng bộ nhớ âm thanh
void cleanupSound(Mix_Chunk* sound) {
    Mix_FreeChunk(sound);
}

void mainsound()
{
    Mix_Chunk* sound = loadSound("hihi.wav");
    if (sound == nullptr) {
        // Đóng SDL và thoát nếu không thể load âm thanh
        close();
        return;
    }
    playSound(sound);

    // Giải phóng bộ nhớ
    cleanupSound(sound);
}


// check cham
bool checkCollision(int characterX, int characterY, int characterWidth, int characterHeight, int obstacleX, int obstacleY, int obstacleWidth, int obstacleHeight) {
    // Kiểm tra xem vị trí của nhân vật có chồng lấp với vật cản hay không
    if (characterX < obstacleX + obstacleWidth &&
        characterX + characterWidth > obstacleX &&
        characterY < obstacleY + obstacleHeight &&
        characterY + characterHeight > obstacleY) {
        return true; // Đã có va chạm
    }
    return false; // Không có va chạm
}


// hàm tải ảnh từ file
SDL_Texture* loadTexture(const std::string& path) {
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    return texture;
}

// load font
SDL_Texture* loadfont(const std::string& path, int fontSize, std::string write) {
    TTF_Font* font = TTF_OpenFont(path.c_str(), fontSize);
    if (font == nullptr) {
        std::cout << "Failed to load font!" << std::endl;
        return nullptr;
    }

    //std::string Score = std::to_string(score);

    SDL_Color textColor = { 255, 255, 255 }; // Màu trắng
    SDL_Surface* fontSurface = TTF_RenderText_Solid(font, write.c_str(), textColor);
    if (fontSurface == nullptr) {
        std::cout << "Failed to render text surface: " << TTF_GetError() << std::endl;
        TTF_CloseFont(font);
        return nullptr;
    }

    SDL_Texture* FontTexture = SDL_CreateTextureFromSurface(gRenderer, fontSurface);
    textWidth = fontSurface->w * 2;
    textHeight = fontSurface->h * 2;
    SDL_FreeSurface(fontSurface);


    if (FontTexture == nullptr) {
        std::cout << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
        TTF_CloseFont(font);
        return nullptr;
    }

    TTF_CloseFont(font);
    return FontTexture;
}
bool Loadscore(int size, std::string path)
{
    gscore = loadfont("Hardpixel.otf", size, path.c_str());
    if (gscore == nullptr)
    {
        std::cout << "Load font is error: " << SDL_GetError();
        return false;
    }
    return true;
}
bool Loadhighscore(int size, std::string path)
{
    ghighscore = loadfont("Hardpixel.otf", size, path.c_str());
    if (ghighscore == nullptr)
    {
        std::cout << "Load font is error: " << SDL_GetError();
        return false;
    }
    return true;
}

void renderscore(int x, int y, int size, std::string path) {
    if (!Loadscore(size, path))
    {
        std::cout << "Load font is Error!\n";
        return;
    }

    if (gscore == nullptr) {
        std::cout << "Failed to create text texture!" << std::endl;
        return;
    }

    SDL_Rect renderQuad = { x, y, textWidth, textHeight };
    SDL_RenderCopy(gRenderer, gscore, NULL, &renderQuad);

    return;
}
void renderhighscore(int x, int y, int size, std::string path) {
    if (!Loadhighscore(size, path))
    {
        std::cout << "Load font is Error!\n";
        return;
    }

    if (gHighScore == nullptr) {
        std::cout << "Failed to create text texture!" << std::endl;
        return;
    }

    SDL_Rect renderQuad1 = { x, y, textWidth, textHeight };
    SDL_RenderCopy(gRenderer, ghighscore, NULL, &renderQuad1);

    return;
}
void updatescore()
{
    float time = endtime / speedscore;
    score = time;
    if (speedscore > 1.0f) speedscore -= 0.1f;
}

void updatehighscore()
{
    
    std::ifstream file("highscore.txt");
    int hgscore;
    int tmp = 0;
    if (file.is_open())
    {
        file >> hgscore;
        tmp = hgscore;
    }
    file.close();
    std::ofstream file1("highscore.txt");
    if (file1.is_open()) {
        if (score > tmp) {
            file1 << score;
            high = score;
        }
        else file1 << tmp;
    }
    file1.close();
    
}




// Hàm khởi tạo SDL và cửa sổ
bool init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    gWindow = SDL_CreateWindow("Tlinhdangiu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gWindowWidth, gWindowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (gWindow == nullptr) {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (gRenderer == nullptr) {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Khởi tạo màu render mặc định là màu trắng
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);

    // Khởi tạo SDL_image
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        return false;
    }

    return true;
}

// Hàm load và hiển thị ảnh nền
bool loadBackground() {
    // Load ảnh nền
    gBackgroundTexture = loadTexture("backgrd.png");
    if (gBackgroundTexture == nullptr) {
        std::cout << "Failed to load background image!" << std::endl;
        return false;
    }
    return true;
}


// Hàm cập nhật cửa sổ
void updateWindowSize(int width, int height) {
    gWindowWidth = width;
    gWindowHeight = height;

    // Set lại kích thước renderer
    SDL_RenderSetLogicalSize(gRenderer, gWindowWidth, gWindowHeight);
}

//Hàm hiển thị ảnh nền
void renderBackground() {
    // Xóa màn hình
    SDL_RenderClear(gRenderer);

    // Vẽ ảnh nền
    SDL_Rect backgroundRect = { 0, 0, gWindowWidth, gWindowHeight };
    SDL_RenderCopy(gRenderer, gBackgroundTexture, nullptr, &backgroundRect);

}

void render() {
    SDL_RenderClear(gRenderer);
    renderBackground();
    renderGround();
    renderSky();
    // renderrain();
    std::string Score = std::to_string(score);
    std::string HighScore = std::to_string(high);
    renderhighscore(xScore + 620, yScore, 36, HighScore);
    renderscore(xScore, yScore, 36, Score);
    

    renderscore();
    renderpause();
    renderObstacle();
    renderCharacter(gCharacterX, gCharacterY);

    SDL_RenderPresent(gRenderer);
}

// Hàm cleanup và thoát chương trình
void close() {

    SDL_DestroyTexture(gSkyTexture);
    SDL_DestroyTexture(gCharacterTexture);
    SDL_DestroyTexture(gBackgroundTexture);
    SDL_DestroyTexture(gObstacle1);
    SDL_DestroyTexture(gObstacle2);
    SDL_DestroyTexture(gObstacle3);
    SDL_DestroyTexture(gObstacle4);
    SDL_DestroyTexture(gObstacle5);
    SDL_DestroyTexture(gLoading);
    SDL_DestroyTexture(gLoading1);
    SDL_DestroyTexture(gMenu);
    SDL_DestroyTexture(gMenu1);
    SDL_DestroyTexture(gscore);
    SDL_DestroyTexture(gGameover);
    SDL_DestroyTexture(gMouse);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    Mix_CloseAudio();
    IMG_Quit();
    SDL_Quit();
}

//load anh nhan vat
bool loadCharacter()
{
    gCharacterTexture = loadTexture("character.png");
    if (gCharacterTexture == nullptr)
    {
        std::cout << "load_Character Error: " << SDL_GetError() << "\n";
        return false;
    }
    return true;

}

//hien thi anh
void renderCharacter(int x, int y)
{
    // ve anh nhan vat tai vi tri (x,y);
    SDL_Rect characterRect = { x,y,gCharacterWidth, gCharacterHeight };
    SDL_RenderCopy(gRenderer, gCharacterTexture, nullptr, &characterRect);

    return;
}

//hàm cập nhạt vị trí của nhân vật
void updateCharacterPosition(int deltaX, int deltaY) {
    /*if (!isJumping) { */// Nếu nhân vật không nhảy
    gCharacterX += deltaX; // Di chuyển theo trục x
    /*}*/
    gCharacterY += deltaY; // Di chuyển theo trục y
}



// Thêm hàm xử lý sự kiện bàn phím de nhan vat di chuyen
void handleKeyPress(SDL_Keycode key) {
    switch (key) {
    case SDLK_LEFT:
        moveLeft(); // Di chuyển sang trái khi nhấn phím trái
        break;
    case SDLK_RIGHT:
        /*updateCharacterPosition(10, 0);*/ // Di chuyển sang phải khi nhấn phím phải
        moveRight();
        break;
    case SDLK_UP:
        jump(); // Bắt đầu nhảy khi nhấn phím lên
        break;
    case SDLK_DOWN:
        updateCharacterPosition(0, 10);
        break;
        /*case SDLK_RETURN:
            pauseGame();
            break;*/
    default:
        break;
    }
}

// ham xu ly nhay
void jump()
{
    if (!isJumping && gCharacterY >= 440) // nhan vat dang khong nhay
    {
        isJumping = true;
        jumpStartY = 440;
    }
}
void moveRight()
{
    if (!ismoveRight) // nhan vat dang khong nhay
    {
        ismoveRight = true;
        jumpStartX = gCharacterX;
    }
}
void moveLeft()
{
    if (!ismoveLeft) // nhan vat dang khong nhay
    {
        ismoveLeft = true;
        jumpStartX = gCharacterX;
    }
}

void jumpCharacter(float deltaTime, int& gCharacterY)
{

    gCharacterY -= Jump_Speed * deltaTime; // khoang cach di chuyen theo trucj y trong mot khung hinh

    if (gCharacterY <= 400 - 150)
    {
        isJumping = false;
    }

}

void moveRightCharacter(float deltaTime, int& gCharacterX)
{
    gCharacterX += Jump_Speed * deltaTime; // khoang cach di chuyen theo trucj y trong mot khung hinh

    if (gCharacterX >= jumpStartX + 50)
    {
        ismoveRight = false;
    }

}

void moveLeftCharacter(float deltaTime, int& gCharacterX)
{
    gCharacterX -= Jump_Speed * deltaTime; // khoang cach di chuyen theo trucj y trong mot khung hinh

    if (gCharacterX <= jumpStartX - 50)
    {
        ismoveLeft = false;
    }

}

// ham di chuyen nhan vat xuong
void fallCharacter(float deltaTime, int previousCharacterY, int& gCharacterY)
{

    // di chuyen xuong duoi
    gCharacterY += Jump_Speed * deltaTime;

    // kien tra xem nhan vat da xuong den vi tri ban dau chua
    if (gCharacterY >= 440)
    {
        gCharacterY = 440; // Đặt vị trí nhân vật về vị trí trước khi nhảy
    }
}


//load anh dat
bool loadGround()
{
    gGroundTexture = loadTexture("ground.png");
    if (gGroundTexture == nullptr)
    {
        std::cout << "Fail to load ground image! " << "\n";
        return false;
    }
    return true;
}

// laod anh bau troi
bool loadSky()
{

    gSkyTexture = loadTexture("cloud.png");
    if (gSkyTexture == nullptr)
    {
        std::cout << "Fail to load ground image! " << "\n";
        return false;
    }
    return true;
}


void renderGround() {
    // Vẽ mặt đất tại vị trí hiện tại
    SDL_Rect groundRect1 = { groundPosX1, gWindowHeight - gGroundHeight, gWindowWidth, gGroundHeight };
    SDL_RenderCopy(gRenderer, gGroundTexture, nullptr, &groundRect1);

    // Vẽ lớp mặt đất thứ hai kế bên lớp đầu tiên
    SDL_Rect groundRect2 = { groundPosX2, gWindowHeight - gGroundHeight, gWindowWidth, gGroundHeight };
    SDL_RenderCopy(gRenderer, gGroundTexture, nullptr, &groundRect2);
}



// Hàm vẽ mây
void renderSky() {
    // Vẽ mây tại vị trí hiện tại
    SDL_Rect skyRect1 = { skyPosX1, 0, gWindowWidth, gSkyHeight };
    SDL_RenderCopy(gRenderer, gSkyTexture, nullptr, &skyRect1);

    // Vẽ lớp mây thứ hai kế bên lớp đầu tiên
    SDL_Rect skyRect2 = { skyPosX2, 0, gWindowWidth, gSkyHeight };
    SDL_RenderCopy(gRenderer, gSkyTexture, nullptr, &skyRect2);
}



// Hàm cập nhật vị trí của mặt đất và mây
void updateGroundandSky() {
    // Cập nhật vị trí của mặt đất và mây bằng cách giảm giá trị x
    groundPosX1 -= 1; // Điều chỉnh tốc độ di chuyển bằng cách thay đổi giá trị này
    groundPosX2 -= 1;
    skyPosX1 -= 2; // Điều chỉnh tốc độ di chuyển của mây
    skyPosX2 -= 2;

    // Nếu mặt đất và mây đã đi hết màn hình, đặt lại vị trí để tạo hiệu ứng vòng lặp
    if (groundPosX1 <= -gWindowWidth) {
        groundPosX1 = gWindowWidth;
    }
    if (groundPosX2 <= -gWindowWidth) {
        groundPosX2 = gWindowWidth;
    }
    if (skyPosX1 <= -gWindowWidth) {
        skyPosX1 = gWindowWidth;
    }
    if (skyPosX2 <= -gWindowWidth) {
        skyPosX2 = gWindowWidth;
    }
}

// xu ly chuong ngai vat
bool loadobstacle()
{
    gObstacle1 = loadTexture("obstacle1.png");
    gObstacle2 = loadTexture("obstacle2.png");
    gObstacle3 = loadTexture("fire1.png");
    gObstacle4 = loadTexture("fire2.png");
    gObstacle5 = loadTexture("fire3.png");
    if (gObstacle1 == nullptr || gObstacle2 == nullptr || gObstacle3 == nullptr || gObstacle4 == nullptr || gObstacle5 == nullptr)
    {
        std::cout << "Faile to load image!\n";
        return false;
    }
    return true;
}

void renderObstacle()
{
    if (ObstacleStartX == 1200)
    {
        srand(time(nullptr));
        random = rand() % 5 + 1;

    }
    if (ObstacleStartX1 == 1200)
    {
        srand(time(nullptr));
        random1 = rand() % 5 + 1;

    }

    if (random == 1)
    {
        // check = true;
         // vẽ chướng ngại vật với góc quay tương ứng
        SDL_Rect obstacleRect1 = { ObstacleStartX, ObstacleStartY, ObstacleX1, ObstacleY1 };
        SDL_RenderCopy(gRenderer, gObstacle1, nullptr, &obstacleRect1);
    }
    else if (random == 2)
    {
        //check = true;

        // tinh toan trung tam cua chuong ngai vat
        int obstacleCenterX = ObstacleStartX + (ObstacleX1 / 2);
        int obstacleCenterY = ObstacleStartY + (ObstacleY1 / 2);
        SDL_Rect obstacleRect2 = { ObstacleStartX, ObstacleStartY, ObstacleX1, ObstacleY1 };
        SDL_RenderCopyEx(gRenderer, gObstacle2, nullptr, &obstacleRect2, obstacleAngle, nullptr, SDL_FLIP_NONE);

        obstacleAngle += 15.0f;
    }
    else if (random == 3)
    {
        //check = true;

        // vẽ chướng ngại vật lửa
        SDL_Rect obstacleRect3 = { ObstacleStartX, ObstacleStartY, ObstacleX3,ObstacleY3 };
        SDL_RenderCopy(gRenderer, gObstacle3, nullptr, &obstacleRect3);
    }

    else if (random == 4)
    {
        //check = true;

        SDL_Rect obstacleRect4 = { ObstacleStartX, ObstacleStartY, ObstacleX4, ObstacleY4 };
        SDL_RenderCopy(gRenderer, gObstacle4, nullptr, &obstacleRect4);

    }
    else if (random == 5)
    {
        //check = true;


        SDL_Rect obstacleRect5 = { ObstacleStartX, ObstacleStartY, ObstacleX5, ObstacleY5 };
        SDL_RenderCopy(gRenderer, gObstacle5, nullptr, &obstacleRect5);

    }

    if (random1 == 1)
    {
        //check = false;
        SDL_Rect obstacleRect1 = { ObstacleStartX1, ObstacleStartY, ObstacleX1, ObstacleY1 };
        SDL_RenderCopy(gRenderer, gObstacle1, nullptr, &obstacleRect1);

        SDL_Rect obstacleRect5 = { ObstacleStartX2, ObstacleStartY, ObstacleX5, ObstacleY5 };
        SDL_RenderCopy(gRenderer, gObstacle5, nullptr, &obstacleRect5);

    }

    else if (random1 == 2)
    {
        // check = false;

        SDL_Rect obstacleRect1 = { ObstacleStartX1, ObstacleStartY, ObstacleX1, ObstacleY1 };
        SDL_RenderCopy(gRenderer, gObstacle1, nullptr, &obstacleRect1);

        SDL_Rect obstacleRect3 = { ObstacleStartX2, ObstacleStartY, ObstacleX3,ObstacleY3 };
        SDL_RenderCopy(gRenderer, gObstacle3, nullptr, &obstacleRect3);

    }

    else if (random1 == 3)
    {
        //check = false;

        SDL_Rect obstacleRect3 = { ObstacleStartX1, ObstacleStartY, ObstacleX3,ObstacleY3 };
        SDL_RenderCopy(gRenderer, gObstacle3, nullptr, &obstacleRect3);

        int obstacleCenterX = ObstacleStartX2 + (ObstacleX1 / 2);
        int obstacleCenterY = ObstacleStartY + (ObstacleY1 / 2);
        SDL_Rect obstacleRect2 = { ObstacleStartX2, ObstacleStartY, ObstacleX1, ObstacleY1 };
        SDL_RenderCopyEx(gRenderer, gObstacle2, nullptr, &obstacleRect2, obstacleAngle, nullptr, SDL_FLIP_NONE);

        obstacleAngle += 15.0f;

    }

    else if (random1 == 4)
    {


        SDL_Rect obstacleRect5 = { ObstacleStartX1, ObstacleStartY, ObstacleX5, ObstacleY5 };
        SDL_RenderCopy(gRenderer, gObstacle5, nullptr, &obstacleRect5);

        SDL_Rect obstacleRect4 = { ObstacleStartX2, ObstacleStartY, ObstacleX4, ObstacleY4 };
        SDL_RenderCopy(gRenderer, gObstacle5, nullptr, &obstacleRect4);
    }

    else if (random1 == 5)
    {


        SDL_Rect obstacleRect5 = { ObstacleStartX1, ObstacleStartY, ObstacleX5, ObstacleY5 };
        SDL_RenderCopy(gRenderer, gObstacle5, nullptr, &obstacleRect5);

        int obstacleCenterX = ObstacleStartX2 + (ObstacleX1 / 2);
        int obstacleCenterY = ObstacleStartY + (ObstacleY1 / 2);
        SDL_Rect obstacleRect2 = { ObstacleStartX2, ObstacleStartY, ObstacleX1, ObstacleY1 };
        SDL_RenderCopyEx(gRenderer, gObstacle2, nullptr, &obstacleRect2, obstacleAngle, nullptr, SDL_FLIP_NONE);

        obstacleAngle += 15.0f;

    }


    if (random == 1 || random == 2 || random == 3 || random == 4 || random == 5)
    {
        ObstacleStartX -= 5; //xu ly them
        if (ObstacleStartX <= 0) ObstacleStartX = 1200;
    }
    if (random1 == 1 || random1 == 2 || random1 == 3 || random1 == 4 || random1 == 5)
    {
        ObstacleStartX1 -= 5; //xu ly them
        ObstacleStartX2 -= 5; //xu ly them
        if (ObstacleStartX2 <= 0)
        {
            ObstacleStartX1 = 1200;
            ObstacleStartX2 = 1500;
        }
    }


    return;
}

// ham chuong ngai vat mua
bool rain()
{
    gRain1 = loadTexture("rain1.png");
    gRain2 = loadTexture("rain2.png");
    gRain3 = loadTexture("rain3.png");

    if (gRain1 == nullptr || gRain2 == nullptr || gRain3 == nullptr)
    {
        std::cout << "Faile to load image!\n";
        return false;
    }
    return true;
}

void renderrain()
{

    srand(time(nullptr));
    random = rand() % 3 + 1;


    if (random == 1)
    {
        // vẽ chướng ngại vật với góc quay tương ứng
        SDL_Rect rain1 = { 100, 100, 17.6, 17.3 };
        SDL_RenderCopy(gRenderer, gRain1, nullptr, &rain1);
    }
    else if (random == 2)
    {
        // tinh toan trung tam cua chuong ngi vat
        SDL_Rect rain2 = { 200, 100, 21.2, 36 };
        SDL_RenderCopy(gRenderer, gRain2, nullptr, &rain2);

    }
    else if (random == 3)
    {
        // vẽ chướng ngại vật lửa
        SDL_Rect rain3 = { 300, 100, 36, 36 };
        SDL_RenderCopy(gRenderer, gRain3, nullptr, &rain3);
    }

}



// load diem
bool loadscore()
{
    gScore = loadTexture("score.png");
    gHighScore = loadTexture("highscore.png");
    if (gScore == nullptr || gHighScore == nullptr)
    {
        std::cout << "Load image score is error: " << SDL_GetError() << "\n";
        return false;
    }
    return true;
}

void renderscore()
{
    SDL_Rect score = { 0, -10, 280, 120 };
    SDL_RenderCopy(gRenderer, gScore, nullptr, &score);
    
    SDL_Rect highscore = { 430, -10, 450, 120 };
    SDL_RenderCopy(gRenderer, gHighScore, nullptr, &highscore);
    return;
}

void loaddata()
{
    // Khởi tạo SDL và cửa sổ

    if (!init()) {
        std::cout << "Failed to initialize!" << std::endl;
        return;
    }

    // load SDL_ttf
    if (TTF_Init() == -1) {
        std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
        SDL_DestroyRenderer(gRenderer);
        SDL_DestroyWindow(gWindow);
        SDL_Quit();
        return;
    }

    // khoi tao SDL_mixer
    if (!initializeSDL())
    {
        std::cout << "Failed to load mixer!\n";
        return;
    }
    std::string Score = std::to_string(score);
    if (!Loadscore(72,Score))
    {
        std::cout << "Load font is Error!\n";
        return;
    }

    loadingimage();
    Menu();
    SDL_Delay(20);




    // Load ảnh nền
    if (!loadBackground()) {
        std::cout << "Failed to load media!" << std::endl;
        close();
        return;
    }




    if (!loadGround())
    {
        std::cout << "Failed to laod image!" << "\n";
        close();
        return;
    }
    if (!loadSky())
    {
        std::cout << "Failed to laod image!" << "\n";
        close();
        return;
    }
    //load nhan vat
    if (!loadCharacter())
    {
        std::cout << "Failed to load character!" << "\n";
        close();
        return;
    }
    if (!loadobstacle())
    {
        std::cout << "Failed to load obstacle!" << "\n";
        close();
        return;
    }

    if (!rain())
    {
        std::cout << "Failed to load rain!" << "\n";
        close();
        return;
    }

    if (!loadscore())
    {
        std::cout << "Failed to load socre!" << "\n";
        close();
        return;
    }
}

// hàm điều khiển chương trình
void control()
{

    //khoi tao va load du lieu truoc khi vao ham control
    /*loaddata();*/

    // Biến lưu thời gian của khung hình trước đó
    Uint32 prevTime = SDL_GetTicks();

    // Biến lưu vị trí trước khi nhảy
    int previousCharacterY = 100;

    // Main loop
    bool quit = false;
    SDL_Event e;

    int Y = gCharacterY;




    while (!quit) {

        //mainsound();
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - prevTime) / 1000.0f; // Chuyển đổi sang giây
        prevTime = currentTime;



        // xử lý sự kiện
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                updateWindowSize(e.window.data1, e.window.data2);
            }

            // xu ly su kien di chuyen
            else if (e.type == SDL_KEYDOWN) {
                handleKeyPress(e.key.keysym.sym);
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if (mouseX >= 1130 && mouseX <= 1180 && mouseY >= 30 && mouseY <= 80)
                {
                    renderMenu();
                    SDL_RenderPresent(gRenderer);
                    pauseGame();
                }

            }

        }

        endtime = currentTime - starttime;
        updatescore();



        // Nếu nhân vật đang nhảy
        if (isJumping) {
            jumpCharacter(deltaTime, gCharacterY); // Thực hiện nhảy của nhân vật
        }

        else { // Nếu nhân vật không nhảy
            // Lưu vị trí trước khi nhảy
            previousCharacterY = Y;

            // Di chuyển nhân vật xuống
            fallCharacter(deltaTime, previousCharacterY, gCharacterY);
            //isJumping = false;
        }


        if (checkCollision(gCharacterX, gCharacterY, gCharacterWidth, gCharacterHeight, ObstacleStartX, ObstacleStartY, ObstacleX1, ObstacleY1) ||
            checkCollision(gCharacterX, gCharacterY, gCharacterWidth, gCharacterHeight, ObstacleStartX1, ObstacleStartY, ObstacleX1, ObstacleY1) ||
            checkCollision(gCharacterX, gCharacterY, gCharacterWidth, gCharacterHeight, ObstacleStartX2, ObstacleStartY, ObstacleX1, ObstacleY1))
        {
            gameover = true;
            break;
        }

        updateGroundandSky();


        // Render

        render();
        /*renderCharacter(gCharacterX, gCharacterY);*/
        SDL_Delay(10);

    }


    OverGame();
    updatehighscore();
    // Thoát chương trình
    close();
    return;

}


bool loadingImage()
{
    gLoading = loadTexture("loading.png");
    gLoading1 = loadTexture("loading1.png");
    if (gLoading == nullptr || gLoading1 == nullptr) {
        std::cerr << "Failed to load menu image!" << std::endl;
        return false;
    }
    return true;
}





void renderLoading()
{
    SDL_Rect loading = { 0, 0, gWindowWidth, gWindowHeight };
    SDL_RenderCopy(gRenderer, gLoading, nullptr, &loading);

    //renderfont();

    static int Loadcurrent = LoadingX;


    if (Loadcurrent < LoadingXend)
    {
        Loadcurrent += 2;
    }
    loadcurrent = Loadcurrent;
    Loading1Pos.push_back(Loadcurrent);

    for (int pos : Loading1Pos)
    {
        SDL_Rect loading1 = { pos, LoadingY, LoadingWidth, LoadingHeigth };
        SDL_RenderCopy(gRenderer, gLoading1, nullptr, &loading1);
    }


    return;
}




// Hàm hiển thị menu
void loadingimage() {
    // Tải ảnh menu từ tệp hình ảnh
    if (!loadingImage())
    {
        std::cout << "Faile to load image!\n";
        return;
    }





    // Vòng lặp xử lý sự kiện cho menu
    bool load = true;
    while (load) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                // Thoát nếu người chơi đóng cửa sổ
                close();
                return;
            }


        }
        //// Tính toán phần trăm đã tải và vẽ thanh tiến trình
        //calcuLoaded(currentRes, totalRes);
        //renderLoadingBar();
        if (loadcurrent >= 1110)
        {
            load = false;
            break;
        }
        //currentRes++;
        //renderfont();
        renderLoading();
        SDL_RenderPresent(gRenderer);

    }

    //// Giải phóng texture của menu

    SDL_DestroyTexture(gLoading);
    SDL_DestroyTexture(gLoading1);

    return;
}


bool menuImage()
{
    gMenu = loadTexture("backgrd.png");
    gMenu1 = loadTexture("menu.png");
    if (gMenu == nullptr && gMenu1 == nullptr)
    {
        std::cout << "Faile to load image! \n";
        return false;
    }
    return true;
}

void renderMenu()
{
    if (!menuImage())
    {
        std::cout << "Faile to load image!\n";
        close();
        return;
    }
    SDL_Rect menu = { 0, 0, gWindowWidth, gWindowHeight };
    SDL_RenderCopy(gRenderer, gMenu, nullptr, &menu);

    SDL_Rect menu1 = { 0, 0, gWindowWidth, gWindowHeight };
    SDL_RenderCopy(gRenderer, gMenu1, nullptr, &menu1);

}


bool loadmouse()
{
    gMouse = loadTexture("mouse0.png");
    if (gMouse == nullptr)
    {
        std::cout << "Faile to load Mouse!\n";
        return false;
    }
    return true;
}

void renderMouse(int x, int y)
{
    //  SDL_RenderClear(gRenderer);
    SDL_Rect mouse = { x, y, 50,50 };
    SDL_RenderCopy(gRenderer, gMouse, nullptr, &mouse);
    SDL_RenderPresent(gRenderer);
    return;
}

void Menu()
{
    // Vòng lặp xử lý sự kiện cho menu
    bool menu = true;
    while (menu) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                // Thoát nếu người chơi đóng cửa sổ
                close();
                return;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if (mouseX >= 520 && mouseX <= 860 && mouseY >= 20 && mouseY <= 160)
                {
                    menu = false;
                    starttime = SDL_GetTicks();
                    return;

                }
                else if (mouseX >= 520 && mouseX <= 860 && mouseY >= 380 && mouseY <= 520)
                {
                    close();
                    return;
                }
               
            }


        }

        //currentRes++;
        //renderfont();
        renderMouse(100, 100);
        renderMenu();
        SDL_RenderPresent(gRenderer);

    }
    SDL_DestroyTexture(gMouse);
    SDL_DestroyTexture(gMenu);
    SDL_DestroyTexture(gMenu1);

    return;

}

bool loadpause()
{
    gPause = loadTexture("continue.png");
    if (gPause == nullptr)
    {
        std::cout << "Failed to load continue image";
        return false;
    }
    return true;
}

void renderpause()
{
    if (!loadpause())
    {
        std::cout << "Faile to load continue image!";
    }
    SDL_Rect pause = { 1140, 10, 48, 48 };
    SDL_RenderCopy(gRenderer, gPause, nullptr, &pause);
    return;
}


bool Gameover()
{
    gGameover = loadTexture("gameover.png");
    if (gGameover == nullptr)
    {
        std::cout << "Faile to load image gameover!\n";
        return false;
    }
    return true;
}

void renderGameover()
{

    SDL_Rect gameOver = { 0,0, gWindowWidth, gWindowHeight };
    SDL_RenderCopy(gRenderer, gGameover, nullptr, &gameOver);

    renderoption();

}

void OverGame()
{
    if (!Gameover())
    {
        std::cout << "Faile to load image!\n";

        return;
    }

    // Vòng lặp xử lý sự kiện cho menu
    bool over = false;
    while (!over) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                // Thoát nếu người chơi đóng cửa sổ
                close();
                return;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if (mouseX >= 1140 && mouseX <= 1190 && mouseY >= 10 && mouseY <= 60)
                {
                    renderMenu();
                    SDL_RenderPresent(gRenderer);
                    pauseGame();
                    control();
                }

            }


        }

        // ve cac hinh nen len man
        std::string Score = std::to_string(score);
        std::string HighScore = std::to_string(high);

        if (!Loadscore(40, Score));
        updatescore();
        updatehighscore();
        renderGameover();
        renderscore(350, 103, 40, Score);
        renderscore(950, 103, 40, HighScore);
        SDL_RenderPresent(gRenderer);
        SDL_Delay(10);
        
        //SDL_Delay(2000);

    }
    

    
    /* Menu();*/

    return;
}



// hamg dung game
void pauseGame() {
    bool paused = true;
    SDL_Event event;

    //Menu();


    // Chờ đợi người chơi ấn một nút để tiếp tục
    while (paused) {
        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {
                // Thoát nếu người chơi đóng cửa sổ
                close();
                return;
            }

            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if (mouseX >= 520 && mouseX <= 860 && mouseY >= 20 && mouseY <= 160)
                {
                    starttime = SDL_GetTicks();
                    ObstacleStartX = 1200;
                    ObstacleStartX1 = 1200;
                    ObstacleStartX2 = 1500;
                    return;
                    paused = false;
                }
                if (mouseX >= 520 && mouseX <= 860 && mouseY >= 380 && mouseY <= 520)
                {
                    close();
                    return;
                }
                if (mouseX >= 520 && mouseX <= 860 && mouseY >= 200 && mouseY <= 340)
                {
                    paused = false;
                    return;
                }
            }

        }
        SDL_Delay(10);
    }

    close();
    // Xóa màn hình đen (nếu cần)
}
