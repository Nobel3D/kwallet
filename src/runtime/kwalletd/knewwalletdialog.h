/**
  * This file is part of the KDE project
  * Copyright (C) 2013 Valentin Rusu <kde@rusu.info>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Library General Public
  * License version 2 as published by the Free Software Foundation.
  *
  * This library is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  * Library General Public License for more details.
  *
  * You should have received a copy of the GNU Library General Public License
  * along with this library; see the file COPYING.LIB.  If not, write to
  * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  * Boston, MA 02110-1301, USA.
  */
#ifndef KNEWWALLETDIALOG_H
#define KNEWWALLETDIALOG_H

#include <QWizard>

#include "ui_knewwalletdialogintro.h"
#include "ui_knewwalletdialoggpg.h"

namespace GpgME
{
class Key;
}

namespace KWallet
{

class KNewWalletDialogIntro;
class KNewWalletDialogGpg;

class KNewWalletDialog : public QWizard
{
    Q_OBJECT
public:
    KNewWalletDialog(const QString &appName, const QString &walletName, QWidget *parent = nullptr);

    bool isBlowfish() const;
    int gpgId() const
    {
        return _gpgId;
    }
    GpgME::Key gpgKey() const;
private:
    KNewWalletDialogIntro   *_intro;
    int                     _introId;
    KNewWalletDialogGpg     *_gpg;
    int                     _gpgId;
};

class KNewWalletDialogIntro : public QWizardPage
{
    Q_OBJECT
public:
    KNewWalletDialogIntro(const QString &appName, const QString &walletName, QWidget *parent = nullptr);
    bool isBlowfish() const;
    int nextId() const Q_DECL_OVERRIDE;
protected Q_SLOTS:
    void onBlowfishToggled(bool);
private:
    Ui_KNewWalletDialogIntro _ui;
};

class KNewWalletDialogGpg : public QWizardPage
{
    Q_OBJECT
public:
    KNewWalletDialogGpg(const QString &appName, const QString &walletName, QWidget *parent = nullptr);
    void initializePage() Q_DECL_OVERRIDE;
    bool isComplete() const Q_DECL_OVERRIDE;
    virtual bool validateCurrentPage();
protected Q_SLOTS:
    void onItemSelectionChanged();
private:
    bool                    _alreadyInitialized;
    Ui_KNewWalletDialogGpg  _ui;
    bool                    _complete;
};

} // namespace

#endif // KNEWWALLETDIALOG_H
