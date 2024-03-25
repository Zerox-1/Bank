#include "model.h"

Model::Model(QObject *parent) : QObject(parent) {
    m_balances.resize(3);
    m_periods.resize(3);
    m_time = QTime(0, 0);
    for (int i = 0; i < 3; ++i) {
        m_timer.append(new QTimer(this));
        connect(m_timer[i], &QTimer::timeout, this, [this, i]() {
            switch (i) {
                case 0: update1(); break;
                case 1: update2(); break;
                case 2: update3(); break;
            }
        });
    }
}

void Model::setBalance(int index, double balance) {
    m_balances[index] = balance;
}

void Model::setPeriod(int index, double period) {
    m_periods[index] = period;
    m_timer[index]->start(10000 * period);
}

void Model::update1() {
    m_totalbalance += m_balances[0];
    emit BalanceChanged();
}

void Model::update2() {
    m_totalbalance += m_balances[1];
    emit BalanceChanged();
}

void Model::update3() {
    m_totalbalance += m_balances[2];
    emit BalanceChanged();
}

double Model::getTotalBalans(){
    return m_totalbalance;
}
