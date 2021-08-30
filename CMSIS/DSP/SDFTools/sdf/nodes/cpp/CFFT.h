/* ----------------------------------------------------------------------
 * Project:      CMSIS DSP Library
 * Title:        CFFT.h
 * Description:  Node for CMSIS-DSP cfft
 *
 * $Date:        30 July 2021
 * $Revision:    V1.10.0
 *
 * Target Processor: Cortex-M and Cortex-A cores
 * -------------------------------------------------------------------- */
/*
 * Copyright (C) 2010-2021 ARM Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _CFFT_H_ 
#define _CFFT_H_

template<typename IN, int inputSize,typename OUT,int outputSize>
class CFFT;

/*

The CMSIS-DSP CFFT F32

*/
template<int inputSize>
class CFFT<float32_t,inputSize,float32_t,inputSize>: public GenericNode<float32_t,inputSize,float32_t,inputSize>
{
public:
    CFFT(FIFOBase<float32_t> &src,FIFOBase<float32_t> &dst):GenericNode<float32_t,inputSize,float32_t,inputSize>(src,dst){
         arm_status status;
         status=arm_cfft_init_f32(&sfft,inputSize>>1);
    };

    int run(){
        float32_t *a=this->getReadBuffer();
        float32_t *b=this->getWriteBuffer();
        memcpy((void*)b,(void*)a,inputSize*sizeof(float32_t));
        arm_cfft_f32(&sfft,b,0,1);
        return(0);
    };

    arm_cfft_instance_f32 sfft;

};

/*

The CMSIS-DSP CFFT Q15

*/
template<int inputSize>
class CFFT<q15_t,inputSize,q15_t,inputSize>: public GenericNode<q15_t,inputSize,q15_t,inputSize>
{
public:
    CFFT(FIFOBase<q15_t> &src,FIFOBase<q15_t> &dst):GenericNode<q15_t,inputSize,q15_t,inputSize>(src,dst){
         arm_status status;
         status=arm_cfft_init_q15(&sfft,inputSize>>1);
    };

    int run(){
        q15_t *a=this->getReadBuffer();
        q15_t *b=this->getWriteBuffer();
        memcpy((void*)b,(void*)a,inputSize*sizeof(q15_t));
        arm_cfft_q15(&sfft,b,0,1);
        return(0);
    };

    arm_cfft_instance_q15 sfft;

};

#endif