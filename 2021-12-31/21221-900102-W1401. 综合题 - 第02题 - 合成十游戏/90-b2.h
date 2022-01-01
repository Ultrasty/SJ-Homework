/* 1851521 软工 沈天宇 */
//放上述源程序的公用说明及其他所需内容
#pragma once
#include"cmd_console_tools.h"
#include<conio.h>
#include<iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;


void play(int choice);
void print_data(int data[10][10], int max_x, int max_y);
void generate_data(int data[10][10], int max_x, int max_y);
void find_congener(int data[10][10], int max_x, int max_y,int x,int y ,int find_result[10][10]);
void print_find_result(int find_result[10][10], int max_x, int max_y);
void print_data_with_color(int data[10][10], int max_x, int max_y, int find_result[10][10]);
void find_congener_recursion(int data[10][10], int max_x, int max_y, int x, int y, int find_result[10][10]);
int merge(int data[10][10], int max_x, int max_y, int x, int y, int find_result[10][10]);
void fall(int data[10][10], int max_x, int max_y);
int get_max_num(int data[10][10], int max_x, int max_y);
void print_background(int max_x, int max_y);
void print_data_block(int data[10][10], int max_x, int max_y);
void print_data_block_with_border(int data[10][10], int max_x, int max_y);
void print_background_with_border(int max_x, int max_y);
void print_one_block(int number, int x, int y, int color = COLOR_BLACK);