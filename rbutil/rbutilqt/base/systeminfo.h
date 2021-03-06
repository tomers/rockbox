/***************************************************************************
 *             __________               __   ___.
 *   Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
 *   Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
 *   Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  <
 *   Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
 *                     \/            \/     \/    \/            \/
 *
 *   Copyright (C) 2010 by Dominik Wenger
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/

#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <QtCore>

class SystemInfo : public QObject
{
    Q_OBJECT
    public:
        //! Type of requested usb-id map
        enum MapType {
            MapDevice,
            MapError,
            MapIncompatible,
        };

        //! All system settings
        enum SystemInfos {
            ManualUrl,
            BleedingUrl,
            BootloaderUrl,
            BootloaderInfoUrl,
            DailyUrl,
            DailyFontUrl,
            DailyVoiceUrl,
            DoomUrl,
            ReleaseUrl,
            ReleaseVoiceUrl,
            ReleaseFontUrl,
            BuildInfoUrl,
            GenlangUrl,
            ThemesUrl,
            ThemesInfoUrl,
            RbutilUrl,
            CurPlatformName,
            CurManual,
            CurBootloaderMethod,
            CurBootloaderName,
            CurBootloaderFile,
            CurBootloaderFilter,
            CurEncoder,
            CurBrand,
            CurName,
            CurBuildserverModel,
            CurConfigureModel,
            CurPlayerPicture,
        };

        enum PlatformType {
            PlatformAll,
            PlatformAllDisabled,
            PlatformBase,
            PlatformBaseDisabled,
            PlatformVariant,
            PlatformVariantDisabled
        };

        //! return a list of all platforms (rbutil internal names)
        static QStringList platforms(enum PlatformType type = PlatformAll,
                                     QString variant="");
        //! returns a map of all languages
        static QMap<QString, QStringList> languages(void);
        //! returns a map of usb-ids and their targets
        static QMap<int, QStringList> usbIdMap(enum MapType type);
        //! get a value from system settings
        static QVariant value(enum SystemInfos info);
        //! get a value from system settings for a named platform.
        static QVariant platformValue(QString platform, enum SystemInfos info);

    private:
        //! you shouldnt call this, its a fully static calls
        SystemInfo() {}
        //! create the setting objects if neccessary
        static void ensureSystemInfoExists();
        //! pointers to our setting objects
        static QSettings *systemInfos;
};

#endif

