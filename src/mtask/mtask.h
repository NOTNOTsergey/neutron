#ifndef MTASK_H
#define MTASK_H

#include "../stdlib.h"

typedef struct {
    uint64_t rax, rbx, rcx, rdx, rsi, rdi, rbp, rsp;
    uint64_t r8,  r9,  r10, r11, r12, r13, r14, r15;
    uint64_t cr3, rip, rflags, cycles, last_cycle, switch_cnt, prev_last_cycle;
} __attribute__((packed)) task_state_t;

typedef struct {
    task_state_t state;
    uint64_t uid;
    uint8_t valid;
    uint8_t priority;
    uint8_t prio_cnt;
    char name[64];
} __attribute__((packed)) task_t;

#define MTASK_TASK_COUNT            32

void mtask_init(void);
void mtask_stop(void);
void mtask_create_task(uint64_t stack_size, char* name, uint8_t priority, void(*func)(void));
void mtask_stop_task(uint64_t uid);
uint64_t mtask_get_uid(void);
task_t* mtask_get_task_list(void);

void mtask_save_state(void);
void mtask_restore_state(void);
void mtask_schedule(void);

#endif