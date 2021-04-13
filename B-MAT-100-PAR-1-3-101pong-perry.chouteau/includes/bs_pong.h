/*
** EPITECH PROJECT, 2020
** bs101pong.h
** File description:
** bs101pong.h
*/

float *xyz_in_vector(float x, float y, float z);
float *sum_vector(float *xyz1, float *xyz2);
float *diff_vector(float *xyz1, float *xyz2);
float *m_vector(float m, float *xyz);
float norm_vector(float *xyz);
float *pos_by_time(float x1, float y1, float z1, float x2, float y2, float z2,float n);
int ball_bat(float x1, float y1, float z1, float x2, float y2, float z2, float n);
float angle_vector(float *xyz);
int main();
