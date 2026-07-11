# ConsultIQ — Consulting Firm Management (Qt / C++ Desktop App)

> **Archived academic project.** Built as a 2nd-year integrated project (2A) at
> [Esprit](https://esprit.tn) by a team of six. It is no longer maintained and is
> published here as a portfolio artifact.

A Windows desktop application for managing a consulting firm — clients, appointments,
projects, invoicing, staff, and reporting — built with **Qt 6 / C++17** on a SQL backend
via ODBC. The project also includes an **Arduino** module driving fire and gas sensors
with an LCD display and buzzer alarm.

## My contribution

I built the **Client Management** module:

- `client.{h,cpp}` — the `Client` entity and its data layer (add, list, delete, update),
  backed by `QSqlQueryModel`
- `newclient.{h,cpp,ui}` — the add-client dialog
- `mainwindow.{h,cpp,ui}` — the client list view: table of clients, add, and delete with
  row selection and confirmation dialogs

## Team & modules

| Member                  | Module                           |
| ----------------------- | -------------------------------- |
| Taha Khouildi           | Client Management                |
| Ines Skhiri             | Appointment Scheduling           |
| Oussama Ajmi            | Project & Task Management        |
| Rahma Hassine           | Payment & Invoicing              |
| Chaima Larbi            | Employee / Consultant Management |
| Mohamed Ridha Ben Mnedi | Reporting & Analytics            |

## Tech stack

- **Language:** C++17
- **Framework:** Qt 6 (Widgets, SQL)
- **Database:** SQL via `QODBC` (ODBC data source)
- **Styling:** custom Qt stylesheet (`style.qss`)
- **Hardware:** Arduino — flame + smoke sensors, I2C LCD, buzzer (`fire_gas_detection.ino`)

## Repository layout

This repository contains **two Qt project files**, from two workstreams developed in
parallel:

| Project file                 | Builds                                                     |
| ---------------------------- | ---------------------------------------------------------- |
| `ClientManagementSystem.pro` | **The Client Management module — this is the one to open.** |
| `ConsultIQ.pro`              | The invoicing / payments workstream (separate module set).  |

The `MainWindow` in this repository is the **Client Management** screen, so it builds
under `ClientManagementSystem.pro`. Opening `ConsultIQ.pro` instead will not compile,
since that project does not include `client.cpp` / `newclient.cpp`.

## Build & run

Requires **Qt 6** with the Widgets and SQL modules, and a C++17 compiler (developed with
MinGW 64-bit on Windows).

1. Open **`ClientManagementSystem.pro`** in Qt Creator.
2. Configure an **ODBC data source** named `Source_Projet2A` pointing at the project
   database.
3. Set your database credentials in `connection.cpp` (`setUserName` / `setPassword`).
   The committed password field is intentionally left blank — credentials are not stored
   in this repository.
4. Build and run.

## Arduino module

`fire_gas_detection.ino` reads a flame sensor and a smoke/gas sensor, shows the current
status on an I2C LCD (`NO DANGER`, `FIRE DETECTED`, `GAS DETECTED`, `FIRE & GAS ALERT`),
and triggers a buzzer when either is detected.

## Notes

Parts of the code and comments are in French. As an academic project delivered under a
course deadline, the codebase reflects those constraints rather than production standards.
