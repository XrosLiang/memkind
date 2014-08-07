/*
 * Copyright (C) 2014 Intel Corperation.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice(s),
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice(s),
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO
 * EVENT SHALL THE COPYRIGHT HOLDER(S) BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <numakind.h>

int main(int argc, char **argv)
{
    const size_t strlen = 512;
    char *default_str = NULL;
    char *hbw_str = NULL;
    char *hbw_hugetlb_str = NULL;
    char *hbw_preferred_str = NULL;
    char *hbw_preferred_hugetlb_str = NULL;

    numakind_init();
    
    default_str = (char *)numakind_malloc(NUMAKIND_DEFAULT, strlen);
    if (default_str == NULL) {
        perror("numakind_malloc()");
        fprintf(stderr, "Unable to allocate default string\n");
        return errno ? -errno : 1;
    }
    hbw_str = (char *)numakind_malloc(NUMAKIND_HBW, strlen);
    if (hbw_str == NULL) {
        perror("numakind_malloc()");
        fprintf(stderr, "Unable to allocate hbw string\n");
        return errno ? -errno : 1;
    }
    hbw_hugetlb_str = (char *)numakind_malloc(NUMAKIND_HBW_HUGETLB, strlen);
    if (hbw_hugetlb_str == NULL) {
        perror("numakind_malloc()");
        fprintf(stderr, "Unable to allocate hbw_hugetlb string\n");
        return errno ? -errno : 1;
    }
    hbw_preferred_str = (char *)numakind_malloc(NUMAKIND_HBW_PREFERRED, strlen);
    if (hbw_preferred_str == NULL) {
        perror("numakind_malloc()");
        fprintf(stderr, "Unable to allocate hbw_preferred string\n");
        return errno ? -errno : 1;
    }
    hbw_preferred_hugetlb_str = (char *)numakind_malloc(NUMAKIND_HBW_PREFERRED_HUGETLB, strlen);
    if (hbw_preferred_hugetlb_str == NULL) {
        perror("numakind_malloc()");
        fprintf(stderr, "Unable to allocate hbw_preferred_hugetlb string\n");
        return errno ? -errno : 1;
    }

    sprintf(default_str, "Hello world from standard memory\n");
    sprintf(hbw_str, "Hello world from high bandwidth memory\n");
    sprintf(hbw_hugetlb_str, "Hello world from high bandwidth 2 MB paged memory\n");
    sprintf(hbw_preferred_str, "Hello world from high bandwidth memory if sufficient resources exist\n");
    sprintf(hbw_preferred_hugetlb_str, "Hello world from high bandwidth 2 MB paged memory if sufficient resources exist\n");

    fprintf(stdout, "%s", default_str);
    fprintf(stdout, "%s", hbw_str);
    fprintf(stdout, "%s", hbw_hugetlb_str);
    fprintf(stdout, "%s", hbw_preferred_str);
    fprintf(stdout, "%s", hbw_preferred_hugetlb_str);

    return 0;
}