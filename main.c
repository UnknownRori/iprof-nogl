#include <assert.h>
#include <stdio.h>
#include <raylib.h>
#include "prof.h"

#define WIDTH 800
#define HEIGHT 600
#define FPS 60
#define FONT_SIZE 30

void print_text(float x, float y, char *str, float r, float g, float b, float a)
{
    // TraceLog(LOG_INFO, "print_text(%f, %f, %s, ...)", x, y, str);
    DrawText(str, x, y, FONT_SIZE, ColorFromNormalized((Vector4){r, g, b, a}));
}

float text_width(char *str)
{
    return MeasureText(str, FONT_SIZE);
}

void draw_rectangle(float x0, float y0, float x1, float y1, float r, float g, float b, float a)
{
    DrawRectangle(x0, y0, x1 - x0, y1 - y0, ColorFromNormalized((Vector4){r, g, b, a}));
}

Prof_Define(subframe);

int main()
{
    InitWindow(WIDTH, HEIGHT, "Iprof");
    SetTargetFPS(FPS);
    float x = 0;
    float y = 0;
    bool record = true;
    int frame_count = 0;
    // Prof_set_report_mode(Prof_SELF_TIME);
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_DOWN)) {
            Prof_move_cursor(1);
        }
        if (IsKeyPressed(KEY_SPACE)) {
            Prof_select();
        }
        TraceLog(LOG_INFO, "Frame = %d", frame_count++);
        BeginDrawing();
            {
                Prof_Begin(frame);
                ClearBackground(GetColor(0x181818FF));
                DrawRectangle(x, y, 100, 100, RED);
                for (int i = 0; i < 10*1000*1000; ++i) {}
                {
                    Prof_Region(subframe);
                    for (int i = 0; i < 50*1000*1000; ++i) {}
                    Prof_End;
                }
                Prof_End;
            }
            Prof_draw_gl(0, 0, WIDTH, HEIGHT, FONT_SIZE, 2, print_text, text_width, draw_rectangle);
        EndDrawing();
        Prof_update(record);
    }
    CloseWindow();
    return 0;
}
