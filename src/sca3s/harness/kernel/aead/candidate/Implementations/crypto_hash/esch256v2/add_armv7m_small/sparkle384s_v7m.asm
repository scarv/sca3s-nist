;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; sparkle384s_v7m.asm: Size-optimized ARMv7-M implementation of SPARKLE384. ;;
;; This file is part of the SPARKLE submission to NIST's LW Crypto Project.  ;;
;; Version 1.1.2 (2020-10-30), see <http://www.cryptolux.org/> for updates.  ;;
;; Authors: The SPARKLE Group (C. Beierle, A. Biryukov, L. Cardoso dos       ;;
;; Santos, J. Groszschaedl, L. Perrin, A. Udovenko, V. Velichkov, Q. Wang).  ;;
;; License: GPLv3 (see LICENSE file), other licenses available upon request. ;;
;; Copyright (C) 2019-2020 University of Luxembourg <http://www.uni.lu/>.    ;;
;; ------------------------------------------------------------------------- ;;
;; This program is free software: you can redistribute it and/or modify it   ;;
;; under the terms of the GNU General Public License as published by the     ;;
;; Free Software Foundation, either version 3 of the License, or (at your    ;;
;; option) any later version. This program is distributed in the hope that   ;;
;; it will be useful, but WITHOUT ANY WARRANTY; without even the implied     ;;
;; warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the  ;;
;; GNU General Public License for more details. You should have received a   ;;
;; copy of the GNU General Public License along with this program. If not,   ;;
;; see <http://www.gnu.org/licenses/>.                                       ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    
    
    THUMB
    PRESERVE8
    
    
    AREA sparkle_code, CODE, READONLY, ALIGN=2
    
    
    EXPORT sparkle384_arm [CODE]
    
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;; REGISTER NAMES AND CONSTANTS ;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    
;; register sptr holds the start address of array 'state'
sptr RN r0
;; register cptr holds the start address of array 'rcon'
cptr RN r1
;; register cnt holds the step counter (for loop termination)
cnt RN r0
;; register step holds the number of steps (parameter 'steps')
step RN r1
;; registers c0w to c5w hold round constants from array 'rcon'
c0w RN r0
c1w RN r0
c2w RN r0
c3w RN r0
c4w RN r0
c5w RN r1
;; registers tmpx, tmpy hold temporary values
tmpx RN r0
tmpy RN r1
;; registers x0w to y5w hold 12 words from array 'state'
x0w RN r2
y0w RN r3
x1w RN r4
y1w RN r5
x2w RN r6
y2w RN r7
x3w RN r8
y3w RN r9
x4w RN r10
y4w RN r11
x5w RN r12
y5w RN lr
    
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;; MACROS FOR SPARKLE384 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    
    MACRO
    PROLOGUE_384
    push    {r4-r12,lr}
    ldm     sptr, {x0w-x5w,y5w}
    push    {sptr,step}
    MEND
    
    MACRO
    EPILOGUE_384
    pop.w   {sptr,step}
    stm     sptr, {x0w-x5w,y5w}
    pop     {r4-r12,pc}
    MEND
    
    MACRO
    ADD_STEP_CNT_384
    ldr.w   cptr, =RCON
    eor     y1w, y1w, cnt
    and     c0w, cnt, #7
    ldr     c0w, [cptr, c0w, lsl #2]
    eor     y0w, y0w, c0w
    MEND
    
    MACRO
    ARX_BOX $xi, $yi, $ci
    add     $xi, $xi, $yi, ror #31
    eor     $yi, $yi, $xi, ror #24
    eor     $xi, $xi, $ci
    add     $xi, $xi, $yi, ror #17
    eor     $yi, $yi, $xi, ror #17
    eors    $xi, $xi, $ci
    adds    $xi, $xi, $yi
    eor     $yi, $yi, $xi, ror #31
    eor     $xi, $xi, $ci
    add     $xi, $xi, $yi, ror #24
    eor     $yi, $yi, $xi, ror #16
    eor     $xi, $xi, $ci
    MEND
    
    MACRO
    LL_TMPX $xi, $xj, $xk
    eor     tmpx, $xi, $xj
    eor     tmpx, tmpx, $xk
    eor     tmpx, tmpx, tmpx, lsl #16
    MEND
    
    MACRO
    LL_TMPY $yi, $yj, $yk
    eor     tmpy, $yi, $yj
    eor     tmpy, tmpy, $yk
    eor     tmpy, tmpy, tmpy, lsl #16
    MEND
    
    MACRO
    ARXBOX_LAYER_384
    ;; ARX-box computations for the three left-side branches (i.e. x[0]-y[2]).
    ldr     c0w, [cptr], #4
    ARX_BOX x0w, y0w, c0w
    ldr     c1w, [cptr], #4
    ARX_BOX x1w, y1w, c1w
    ldr     c2w, [cptr], #4
    ARX_BOX x2w, y2w, c2w
    ;; ARX-box computations for the three right-side branches (i.e. x[3]-y[5]).
    ldr     c3w, [cptr], #4
    ARX_BOX x3w, y3w, c3w
    ldm.w   cptr, {c4w,c5w}
    ARX_BOX x4w, y4w, c4w
    ARX_BOX x5w, y5w, c5w
    MEND
    
    MACRO
    LINEAR_LAYER_384
    ;; First part of Feistel round: tmpx and tmpy are computed and XORED to the
    ;; y-words and x-words of the right-side branches (i.e. to y[3], y[4], y[5]
    ;; and to x[3], x[4], x[5]). Note that y[5] and x[5] are stored in register
    ;; tmpx and tmpy (and not in register y5w and x5w) to reduce the execution
    ;; time of the subsequent branch permutation.
    LL_TMPX x0w, x1w, x2w
    eor     y3w, y3w, tmpx, ror #16
    eor     y4w, y4w, tmpx, ror #16
    eor     tmpx, y5w, tmpx, ror #16
    LL_TMPY y0w, y1w, y2w
    eor     x3w, x3w, tmpy, ror #16
    eor     x4w, x4w, tmpy, ror #16
    eor     tmpy, x5w, tmpy, ror #16
    ;; Branch permutation: 1-branch left-rotation of the right-side branches
    ;; along with a swap of the left and right branches (via register writes).
    ;; Also combined with the branch permutation is the second Feistel part,
    ;; in which the left-side branches are XORed with the result of the first
    ;; Feistel part.
    mov.w   y5w, y2w
    eor     y2w, y3w, y0w
    mov.w   y3w, y0w
    eor     y0w, y4w, y1w
    mov.w   y4w, y1w
    eor     y1w, tmpx, y5w
    mov.w   x5w, x2w
    eor     x2w, x3w, x0w
    mov.w   x3w, x0w
    eor     x0w, x4w, x1w
    mov.w   x4w, x1w
    eor     x1w, tmpy, x5w
    MEND
    
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;; SPARKLE384 PERMUTATION (BRANCH-UNROLLED) ;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    
;; Function prototype:
;; -------------------
;; void sparkle384_arm(uint32_t *state, int steps)
;;
;; Parameters:
;; -----------
;; state: pointer to an uint32_t-array containing the 12 state words
;; steps: number of steps
;;
;; Return value:
;; -------------
;; None
    
sparkle384_arm PROC
    PROLOGUE_384            ;; push callee-saved registers and load state
    movs cnt, #0            ;; initialize step-counter
loop_384                    ;; start of loop
    push.w {cnt,step}       ;; push step-counter and 'steps' to free registers
    ADD_STEP_CNT_384        ;; macro to add step-counter to state
    ARXBOX_LAYER_384        ;; macro for the ARXBOX layer
    LINEAR_LAYER_384        ;; macro for the linear layer
    pop {cnt,step}          ;; restore step-counter and 'steps' from stack
    adds cnt, #1            ;; increment step-counter
    teq cnt, step           ;; test whether step-counter equals 'steps'
    bne loop_384            ;; if not then branch to start of loop
    EPILOGUE_384            ;; store state and pop callee-saved registers
    ENDP
    
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;; SPARKLE ROUND CONSTANTS ;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    
;; This implementation places the round constants in the .data segment, which
;; means they are loaded from RAM during the computation of the ARX-boxes. It
;; would also be possible to place them in the .rodata segment (by replacing
;; the "READWRITE" attribute in the AREA directive below by "READONLY") so that
;; they are loaded from flash, which reduces the RAM consumption by 32 bytes,
;; but may increase the execution time on devices with a high number of flash
;; wait states.
    
    
    AREA sparkle_rcon, DATA, READWRITE, ALIGN=2
    
    
;; round constants
RCON DCD 0xB7E15162, 0xBF715880, 0x38B4DA56, 0x324E7738, \
         0xBB1185EB, 0x4F7C7B57, 0xCFBFA1C8, 0xC2B3293D
    
    
    END
