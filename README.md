# GAME: JUMPING                                    
                                            
# I. GIỚI THIỆU
- Chào mừng bạn đến với JUMPING! Đây là một trò chơi đơn giản và giải trí được lấy cảm hứng từ trò chơi "Con Khủng Long" trong trình duyệt Google Chrome.
-  Trong trò chơi này, bạn sẽ điều khiển một nhân vật và cố gắng tránh những chướng ngại vật để giành điểm cao nhất.
- Tao ra bởi ngôn ngữ C, C++, SDL2.
![loading3](https://github.com/ntlinhhhhhh/Jumping/assets/160174186/bb8a8d13-98c9-4438-a204-4be833fd7ec1)

![gtgame](https://github.com/ntlinhhhhhh/Jumping/assets/160174186/e9af9e70-7bcf-432c-98d4-e4517afaadad)

## II. CÁCH CHƠI

1. Khởi động game bằng cách chạy file thực thi hoặc mở trình biên dịch và chạy mã nguồn.
2. Sử dụng các phím mũi tên hoặc phím cách để điều khiển nhân vật.
3. Tránh va chạm với các chướng ngại vật bằng cách nhảy qua chúng.
4. Điểm số của bạn sẽ tăng dần theo thời gian. Xem bạn có thể đạt được điểm số cao nhất nào!



![Screenshot 2024-05-13 033630](https://github.com/ntlinhhhhhh/Jumping/assets/160174186/11577f17-8735-4bf8-9e08-61feaaf1b310)


## III. TÍNH NĂNG

- Đồ họa đơn giản nhưng đẹp mắt.
- Có âm thanh sinh đông
- Điểm số cao nhất được lưu lại để bạn có thể thách thức bản thân.
  
![Screenshot 2024-05-13 034545](https://github.com/ntlinhhhhhh/Jumping/assets/160174186/691056b5-017f-4fe0-84e3-69ce6f9c2f04)

## IV. Hướng dẫn cài đặt

> Cách cài đặt thư viện SDL2
- Bước 1: Tải các thư viện từ trang web chính thức: (bản-VC.zip)
  1. SDL2: https://github.com/libsdl-org/SDL/releases
  2. SDL2_image: https://github.com/libsdl-org/SDL_image/releases
  3. SDL2_mixer: https://github.com/libsdl-org/SDL_mixer/releases
  4. SDL2_ttf: https://github.com/libsdl-org/SDL_ttf/releases
- Bước 2: Link thư viện với dự án
  + Chọn vào project, nhấp chuột phải và chọn properties
  ![Screenshot 2024-05-22 084020](https://github.com/ntlinhhhhhh/Jumping/assets/160174186/3ade927d-a40d-42f5-8bf7-041a1b9dd3cb)
  ![Screenshot 2024-05-22 084038](https://github.com/ntlinhhhhhh/Jumping/assets/160174186/b9ab65d6-324c-4449-a7b0-fd7b58b0db5a)
  + Khi hiện ra của sổ properties, chọn phần VC++ Directories

![Screenshot 2024-05-22 084107](https://github.com/ntlinhhhhhh/Jumping/assets/160174186/3e057756-dfd0-41de-92f5-acc0cb6318d3)
  + Chọn Include Directories, Libary Directories, Libary WinRT Directories để thêm đường dẫn
    

![Screenshot 2024-05-22 084639](https://github.com/ntlinhhhhhh/Jumping/assets/160174186/8a897d0a-affc-4940-91b8-da551c97beab)

+ Tiếp tục chọn phần Linker -> Input -> Additional Dependencies và thêm: SDL2.lib, SDL2main.lib, SDL2_image.lib, SDL2_mixer.lib, SDL2_ttf.lib


![Screenshot 2024-05-22 084944](https://github.com/ntlinhhhhhh/Jumping/assets/160174186/ff80565e-70df-4390-8ae8-628cf96f478e)
+ chon Apply->OK để hoàn thành việc thêm thư viện

![Screenshot 2024-05-22 084944](https://github.com/ntlinhhhhhh/Jumping/assets/160174186/9f3a5f92-d9e3-4e01-8f11-b396f24f1b60)

- Tải xuống hoặc sao chép mã nguồn của game từ kho lưu trữ.
- Mở trình biên dịch và tải dự án.
- Chạy game bằng cách nhấn nút "PLAY". 
![menu](https://github.com/ntlinhhhhhh/Jumping/assets/160174186/112075f7-d192-4da1-953a-1c0b4871b080)

# V. Lưu ý
> Đây là phiên bản demo hoặc phiên bản beta của trò chơi và có thể chưa hoàn thiện.
> Mọi ý kiến đóng góp và báo cáo lỗi đều được đánh giá cao.

# Nguồn tham khảo
- Chat GPT
- Nguồn hình ảnh: pixabay, pixlr,...
  
> Chúc bạn có những phút giây vui vẻ với JUMPING!


