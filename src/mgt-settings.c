/* mgt-settings.c
 *
 * Copyright 2023 Mohammed Sadiq <sadiq@sadiqpk.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author(s):
 *   Mohammed Sadiq <sadiq@sadiqpk.org>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#define G_LOG_DOMAIN "mgt-settings"

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "mgt-settings.h"
#include "mgt-log.h"

/**
 * SECTION: mgt-settings
 * @title: MgtSettings
 * @short_description: The Application settings
 * @include: "mgt-settings.h"
 *
 * A class that handles application specific settings, and
 * to store them to disk.
 */

struct _MgtSettings
{
  GObject    parent_instance;

  GSettings *app_settings;
  gboolean   first_run;
};

G_DEFINE_TYPE (MgtSettings, mgt_settings, G_TYPE_OBJECT)


static void
mgt_settings_dispose (GObject *object)
{
  MgtSettings *self = (MgtSettings *)object;

  MGT_TRACE_MSG ("disposing settings");

  g_settings_set_string (self->app_settings, "version", PACKAGE_VERSION);
  g_settings_apply (self->app_settings);

  G_OBJECT_CLASS (mgt_settings_parent_class)->dispose (object);
}

static void
mgt_settings_class_init (MgtSettingsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->dispose = mgt_settings_dispose;
}

static void
mgt_settings_init (MgtSettings *self)
{
  g_autofree char *version = NULL;

  self->app_settings = g_settings_new (PACKAGE_ID);
  version = g_settings_get_string (self->app_settings, "version");

  if (!g_str_equal (version, PACKAGE_VERSION))
    self->first_run = TRUE;

  g_settings_delay (self->app_settings);
}

/**
 * mgt_settings_new:
 *
 * Create a new #MgtSettings
 *
 * Returns: (transfer full): A #MgtSettings.
 * Free with g_object_unref().
 */
MgtSettings *
mgt_settings_new (void)
{
  return g_object_new (MGT_TYPE_SETTINGS, NULL);
}

/**
 * mgt_settings_save:
 * @self: A #MgtSettings
 *
 * Save modified settings to disk.  By default,
 * the modified settings are saved to disk only
 * when #MgtSettings is disposed.  Use this
 * to force save to disk.
 */
void
mgt_settings_save (MgtSettings *self)
{
  g_return_if_fail (MGT_IS_SETTINGS (self));

  g_settings_apply (self->app_settings);
}

/**
 * mgt_settings_get_is_first_run:
 * @self: A #MgtSettings
 *
 * Get if the application has ever launched after install
 * or update.
 *
 * Returns: %TRUE for the first launch of application after
 * install or update.  %FALSE otherwise.
 */
gboolean
mgt_settings_get_is_first_run (MgtSettings *self)
{
  g_return_val_if_fail (MGT_IS_SETTINGS (self), FALSE);

  return self->first_run;
}

/**
 * mgt_settings_get_window_maximized:
 * @self: A #MgtSettings
 *
 * Get the window maximized state as saved in @self.
 *
 * Returns: %TRUE if maximized.  %FALSE otherwise.
 */
gboolean
mgt_settings_get_window_maximized (MgtSettings *self)
{
  g_return_val_if_fail (MGT_IS_SETTINGS (self), FALSE);

  return g_settings_get_boolean (self->app_settings, "window-maximized");
}

/**
 * mgt_settings_set_window_maximized:
 * @self: A #MgtSettings
 * @maximized: The window state to save
 *
 * Set the window maximized state in @self.
 */
void
mgt_settings_set_window_maximized (MgtSettings *self,
                                   gboolean     maximized)
{
  g_return_if_fail (MGT_IS_SETTINGS (self));

  g_settings_set_boolean (self->app_settings, "window-maximized", !!maximized);
}

/**
 * mgt_settings_get_window_geometry:
 * @self: A #MgtSettings
 * @geometry: (out): A #GdkRectangle
 *
 * Get the window geometry as saved in @self.
 */
void
mgt_settings_get_window_geometry (MgtSettings  *self,
                                  GdkRectangle *geometry)
{
  g_return_if_fail (MGT_IS_SETTINGS (self));
  g_return_if_fail (geometry != NULL);

  g_settings_get (self->app_settings, "window-size", "(ii)",
                  &geometry->width, &geometry->height);
  geometry->x = geometry->y = -1;
}

/**
 * mgt_settings_set_window_geometry:
 * @self: A #MgtSettings
 * @geometry: A #GdkRectangle
 *
 * Set the window geometry in @self.
 */
void
mgt_settings_set_window_geometry (MgtSettings  *self,
                                  GdkRectangle *geometry)
{
  g_return_if_fail (MGT_IS_SETTINGS (self));
  g_return_if_fail (geometry != NULL);

  g_settings_set (self->app_settings, "window-size", "(ii)",
                  geometry->width, geometry->height);
}
