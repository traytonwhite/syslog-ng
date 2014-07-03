/*
 * Copyright (c) 2002-2014 BalaBit IT Ltd, Budapest, Hungary
 * Copyright (c) 1998-2014 Balázs Scheidler
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As an additional exemption you are allowed to compile & link against the
 * OpenSSL libraries as published by the OpenSSL project. See the file
 * COPYING for details.
 *
 */
#ifndef MAINLOOP_IO_WORKER_H
#define MAINLOOP_IO_WORKER_H 1

#include "mainloop-worker.h"

#include <iv_work.h>

typedef struct _MainLoopIOWorkerJob
{
  void (*work)(gpointer user_data);
  void (*completion)(gpointer user_data);
  gpointer user_data;
  gboolean working:1;
  struct iv_work_item work_item;
} MainLoopIOWorkerJob;

void main_loop_io_worker_job_init(MainLoopIOWorkerJob *self);
void main_loop_io_worker_job_submit(MainLoopIOWorkerJob *self);

void main_loop_io_worker_add_options(GOptionContext *ctx);

void main_loop_io_worker_init(void);
void main_loop_io_worker_deinit(void);
void main_loop_maximalize_worker_threads(int max_threads);
#endif
