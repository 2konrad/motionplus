/*
 *    picture.h
 *
 *      Copyright 2002 by Jeroen Vreeken (pe1rxq@amsat.org)
 *      Portions of this file are Copyright by Lionnel Maugis
 *      This software is distributed under the GNU public license version 2
 *      See also the file 'COPYING'.
 *
 */
#ifndef _INCLUDE_PICTURE_H_
#define _INCLUDE_PICTURE_H_

    #include "motion.h"

    void overlay_smartmask(struct ctx_cam *cam, unsigned char *);
    void overlay_fixed_mask(struct ctx_cam *cam, unsigned char *);
    void put_fixed_mask(struct ctx_cam *cam, const char *);
    void overlay_largest_label(struct ctx_cam *cam, unsigned char *);
    int put_picture_memory(struct ctx_cam *cam, unsigned char*, int, unsigned char *, int, int, int);
    void put_picture(struct ctx_cam *cam, char *, unsigned char *, int);
    unsigned char *get_pgm(FILE *, int, int);
    void preview_save(struct ctx_cam *cam);
    void pic_scale_img(int width_src, int height_src, unsigned char *img_src, unsigned char *img_dst);

    unsigned prepare_exif(unsigned char **, const struct ctx_cam *cam, const struct timespec *, const struct ctx_coord *);

#endif /* _INCLUDE_PICTURE_H_ */