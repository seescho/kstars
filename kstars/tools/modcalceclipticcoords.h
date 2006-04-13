/***************************************************************************
                          modcalceclipticcoords.h  -  description
                             -------------------
    begin                : Fri May 14 2004
    copyright            : (C) 2004 by Pablo de Vicente
    email                : p.devicente@wanadoo.es
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef MODCALCECLIPTICCOORDS_H_
#define MODCALCECLIPTICCOORDS_H_

#include "modcalceclipticcoordsdlg.h"
#include "dms.h"

/**
  * Class which implements the KStars calculator module to compute
  * geocentric ecliptic coordinates to/from geocentric equatorial coordinates.
  *
  * Inherits QWidget
  *@author Pablo de Vicente
  */
class modCalcEclCoords : public QFrame, public Ui::modCalcEclCoordsDlg  {

Q_OBJECT

public:
	
	modCalcEclCoords(QWidget *p);
	~modCalcEclCoords();

	void getEclCoords (void);
	void getEquCoords (void);
	void showEquCoords(void);
	void showEclCoords(void);
	void EclToEqu(void);
	void EquToEcl(void);
	
public slots:

	void slotClearCoords (void);
	void slotComputeCoords (void);
	void slotEclLatCheckedBatch(void);
	void slotEclLongCheckedBatch(void);
	void slotRaCheckedBatch(void);
	void slotDecCheckedBatch(void);
	void slotEpochCheckedBatch(void);
	void slotInputFile(void);
	void slotOutputFile(void);
	void slotRunBatch();

private:
	void equCheck(void);
	void eclCheck(void);
	void processLines( QTextStream &is );

	dms eclipLong, eclipLat, raCoord, decCoord;
	QString epoch;
	bool eclInputCoords;
};
#endif

