#include "mcx8316a.h"

#include <qdebug.h>
#include <qfile.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFileDialog>

mcx8316a::mcx8316a()
{

}


QString mcx8316a::doTi()
{
    QString fileName = QFileDialog::getOpenFileName(NULL, "Open JSON", "", "JSON Files (*.json)");
    QString cFile = "#include \"mu_bldc_ti.h\"\r\n";
    cFile += "void ti_init(void) {\r\n";

    QString val;
    QFile file;
    file.setFileName(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());

    //get the jsonObject
    QJsonObject jObject = doc.object();

    QVariantMap mainMap = jObject.toVariantMap();
    QVariantList localList = mainMap["data"].toList();

    size_t msize = localList.size();
    qDebug() << "localList Size" << msize;
    for (int k=0; k < msize;k++)
    {
        QVariantList firstList = localList.at(k).toList();
        int ls = firstList.size();
        qDebug() << "localList 0 " <<ls;
        for (int i=0; i<ls; i++)
        {
            QVariantMap one = firstList.at(i).toMap();
            QString id  = one["id"].toString();
            QString value = one["value"].toString();
            AddTiConfigLine( cFile,id, value);
        }
    }

    cFile += "}\r\n";

    qDebug() << "cFile:" << cFile;

    QString filename = fileName.replace(".json",".c");
    QFile cfile( filename );
    if ( cfile.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &cfile );
        stream << cFile << endl;
    }
    //   qDebug() << dataMap["name"].toString();
    return cFile;
}

void mcx8316a::AddTiConfigLine(QString &line,QString id, QString val)
{
    QString pre = "TI_I2C_bus_write(";
    QString post = ");\r\n";
    if (id.startsWith("isd_config"))
    {
#ifdef TI_TRAPEZUID		
        QString add = pre + "TI_MCT8316A_ISD_CONFIG," + val + post;
#else
		QString add = pre + "TI_MCF8316A_ISD_CONFIG," + val + post;
#endif
	
        line += add;
        return;
    }
    if (id.startsWith("motor_startup1"))
    {
		#ifdef TI_TRAPEZUID		
        QString add = pre + "TI_MCT8316A_MOTOR_STARTUP1," + val + post;
#else
		QString add = pre + "TI_MCF8316A_MOTOR_STARTUP1," + val + post;
#endif
        
        line += add;
        return;
    }
    if (id.startsWith("motor_startup2"))
    {
		#ifdef TI_TRAPEZUID		
			QString add = pre + "TI_MCT8316A_MOTOR_STARTUP2," + val + post;
		#else
			QString add = pre + "TI_MCF8316A_MOTOR_STARTUP2," + val + post;
		#endif
		
        line += add;
        return;
    }

    if (id.startsWith("closed_loop1"))
    {        
		#ifdef TI_TRAPEZUID		
			QString add = pre + "TI_MCT8316A_CLOSED_LOOP1," + val + post;   
		#else
			QString add = pre + "TI_MCF8316A_CLOSED_LOOP1," + val + post;
		#endif
        line += add;
        return;
    }

    if (id.startsWith("closed_loop2"))
    {
        
		#ifdef TI_TRAPEZUID		
			QString add = pre + "TI_MCT8316A_CLOSED_LOOP2," + val + post;
		#else
			QString add = pre + "TI_MCF8316A_CLOSED_LOOP2," + val + post;
		#endif
        line += add;
        return;
    }

    if (id.startsWith("closed_loop3"))
    {
        
		#ifdef TI_TRAPEZUID		
			QString add = pre + "TI_MCT8316A_CLOSED_LOOP3," + val + post;
		#else
			QString add = pre + "TI_MCF8316A_CLOSED_LOOP3," + val + post;
		#endif
        line += add;
        return;
    }

    if (id.startsWith("closed_loop4"))
    {        
		#ifdef TI_TRAPEZUID		
			QString add = pre + "TI_MCT8316A_CLOSED_LOOP4," + val + post;   
		#else
			QString add = pre + "TI_MCF8316A_CLOSED_LOOP4," + val + post;   
		#endif
        line += add;
        return;
    }

    if (id.startsWith("const_speed"))
    {
        QString add = pre + "TI_MCx8316A_CONST_SPEED," + val + post;
        line += add;
        return;
    }

    if (id.startsWith("const_pwr"))
    {
        QString add = pre + "TI_MCT8316A_CONST_PWR," + val + post;
        line += add;
        return;
    }

    if (id.startsWith("150_deg_two_ph_profile"))
    {
        QString add = pre + "TI_MCT8316A_150_DEG_TWO_PH_PROFILE," + val + post;
        line += add;
        return;
    }

    if (id.startsWith("150_deg_three_ph_profile"))
    {
        QString add = pre + "TI_MCT8316A_150_DEG_THREE_PH_PROFILE," + val + post;
        line += add;
        return;
    }

    if (id.startsWith("trap_config1"))
    {
        QString add = pre + "TI_MCT8316A_TRAP_CONFIG1," + val + post;
        line += add;
        return;
    }

    if (id.startsWith("trap_config2"))
    {
        QString add = pre + "TI_MCT8316A_TRAP_CONFIG2," + val + post;
        line += add;
        return;
    }

    if (id.startsWith("fault_config1"))
    {

		#ifdef TI_TRAPEZUID		
			QString add = pre + "TI_MCT8316A_FAULT_CONFIG1," + val + post;			
		#else
			QString add = pre + "TI_MCF8316A_FAULT_CONFIG1," + val + post;
		#endif
        line += add;
        return;
    }

    if (id.startsWith("fault_config2"))
    {        
		#ifdef TI_TRAPEZUID		
				QString add = pre + "TI_MCT8316A_FAULT_CONFIG2," + val + post;		
		#else
			QString add = pre + "TI_MCF8316A_FAULT_CONFIG2," + val + post;
		#endif
        line += add;
        return;
    }

    if (id.startsWith("gd_config1"))
    {
        QString add = pre + "TI_MCx8316A_GD_CONFIG1," + val + post;
        line += add;
        return;
    }

    if (id.startsWith("gd_config2"))
    {
        QString add = pre + "TI_MCx8316A_GD_CONFIG2," + val + post;
        line += add;
        return;
    }

    if (id.startsWith("pin_config1"))
    {
        QString add = pre + "TI_MCT8316A_PIN_CONFIG1," + val + post;
        line += add;
        return;
    }

    if (id.startsWith("pin_config2"))
    {
        QString add = pre + "TI_MCT8316A_PIN_CONFIG2," + val + post;
        line += add;
        return;
    }

    if (id == "device_config")
    {		
		QString add = pre + "TI_MCT8316A_DEVICE_CONFIG," + val + post;					
        line += add;
        return;
    }
	if (id == "device_config1")
    {		
	    QString add = pre + "TI_MCF8316A_DEVICE_CONFIG1," + val + post;	
        line += add;
        return;
    }
	if (id == "device_config2")
    {		
	    QString add = pre + "TI_MCF8316A_DEVICE_CONFIG2," + val + post;	
        line += add;
        return;
    }


    if (id.startsWith("peri_config"))
    {
        QString add = pre + "TI_MCF8316A_PERI_CONFIG1," + val + post;
        line += add;
        return;
    }

    if (id.startsWith("gate_driver_fault_status"))
    {
		// status just read.
        //QString add = pre + "TI_MCT8316A_GATE_DRIVER_FAULT_STATUS," + val + post;
        //line += add;
        return;
    }

    if (id.startsWith("controller_fault_status"))
    {
		// // status just read.
        //QString add = pre + "TI_MCT8316A_CONTROLLER_FAULT_STATUS," + val + post;
        //line += add;
        return;
    }

    if (id.startsWith("sys_status1"))
    {
        QString add = pre + "TI_MCT8316A_SYS_STATUS1," + val + post;
        line += add;
        return;
    }

    if (id.startsWith("sys_status2"))
    {
        QString add = pre + "TI_MCT8316A_SYS_STATUS2," + val + post;
        line += add;
        return;
    }

    if (id.startsWith("sys_status3"))
    {
        QString add = pre + "TI_MCT8316A_SYS_STATUS3," + val + post;
        line += add;
        return;
    }



    if (id.startsWith("device_ctrl"))
    {
        QString add = pre + "TI_MCT8316A_DEVICE_CTRL," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("algo_ctrl1"))
    {
        QString add = pre + "TI_MCF8316A_ALGO_CTRL1," + val + post;
        line += add;
        return;
    }

    if (id.startsWith("ana_trim"))
    {
        return;  // Ignored no info?! 3-10
    }

    if (id.startsWith("algo_reserved"))
    {
        return;  // Ignored no info?! 1-3
    }


    if (id.startsWith("rev_drive_config"))
    {
        QString add = pre + "TI_MCF8316A_REV_DRIVE_CONFIG," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("speed_profiles1"))
    {
        QString add = pre + "TI_MCF8316A_SPEED_PROFILES1," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("speed_profiles2"))
    {
        QString add = pre + "TI_MCF8316A_SPEED_PROFILES2," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("speed_profiles3"))
    {
        QString add = pre + "TI_MCF8316A_SPEED_PROFILES3," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("speed_profiles4"))
    {
        QString add = pre + "TI_MCF8316A_SPEED_PROFILES4," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("speed_profiles5"))
    {
        QString add = pre + "TI_MCF8316A_SPEED_PROFILES5," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("speed_profiles6"))
    {
        QString add = pre + "TI_MCF8316A_SPEED_PROFILES6," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("pin_config"))
    {
        QString add = pre + "TI_MCF8316A_PIN_CONFIG," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("int_algo_1"))
    {
        QString add = pre + "TI_MCF8316A_INT_ALGO_1," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("int_algo_2"))
    {
        QString add = pre + "TI_MCF8316A_INT_ALGO_2," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("algo_status"))
    {
		// RO
        //QString add = pre + "TI_MCF8316A_ALGO_STATUS," + val + post;
        //line += add;
        return;
    }
    if (id.startsWith("mtr_params"))
    {
		// RO
        //QString add = pre + "TI_MCF8316A_MTR_PARAMS," + val + post;
        //line += add;
        return;
    }
    if (id.startsWith("algo_status_mpet"))
    {
        //QString add = pre + "TI_MCF8316A_ALGO_STATUS_MPET," + val + post;
        //line += add;
        return;
    }
	if (id== "dev_ctrl")
    {
        QString add = pre + "TI_MCF8316A_DEV_CTRL," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("dev_ctrl1"))
    {
        QString add = pre + "TI_MCF8316A_ALGO_CTRL1," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("algo_ctrl2"))
    {
        QString add = pre + "TI_MCF8316A_ALGO_CTRL2," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("current_pi"))
    {
        QString add = pre + "TI_MCF8316A_CURRENT_PI," + val + post;
        line += add;
        return;
    }
    if (id.startsWith("speed_pi"))
    {
        QString add = pre + "TI_MCF8316A_SPEED_PI," + val + post;
        line += add;
        return;
    }

    /*
    AddTiConfigLine UNHANDELD:  "dac_1"  value:  "0x00000000"
    AddTiConfigLine UNHANDELD:  "dac_2"  value:  "0x00000000"
*/

    if (id.startsWith("algorithm_state")) return; // Read only
    if (id.startsWith("fg_speed_fdbk"))   return; // Read only
    if (id.startsWith("bus_current"))                return; // Read only
    if (id.startsWith("phase_current_a"))                return; // Read only
    if (id.startsWith("phase_current_b"))                return; // Read only
    if (id.startsWith("phase_current_c"))                return; // Read only
    if (id.startsWith("csa_gain_feedback"))                return; // Read only
    if (id.startsWith("voltage_gain_feedback"))                return; // Read only
    if (id.startsWith("vm_voltage"))                return; // Read only
    if (id.startsWith("phase_voltage_va"))                return; // Read only
    if (id.startsWith("phase_voltage_vb"))                return; // Read only
    if (id.startsWith("phase_voltage_vc"))                return; // Read only
    if (id.startsWith("sin_commutation_angle"))                return; // Read only
    if (id.startsWith("cos_commutation_angle"))                return; // Read only
    if (id.startsWith("ialpha"))                return; // Read only
    if (id.startsWith("ibeta"))                return; // Read only
    if (id.startsWith("valpha"))                return; // Read only
    if (id.startsWith("vbeta"))                return; // Read only
    if (id.startsWith("id"))                return; // Read only
    if (id.startsWith("iq"))                return; // Read only
    if (id.startsWith("vd"))                return; // Read only
    if (id.startsWith("vq"))                return; // Read only
    if (id.startsWith("iq_ref_rotor_align"))                return; // Read only
    if (id.startsWith("speed_ref_open_loop"))                return; // Read only
    if (id.startsWith("iq_ref_open_loop"))                return; // Read only
    if (id.startsWith("speed_ref_closed_loop"))                return; // Read only
    if (id.startsWith("id_ref_closed_loop"))                return; // Read only
    if (id.startsWith("iq_ref_closed_loop"))                return; // Read only
    if (id.startsWith("isd_state"))                return; // Read only
    if (id.startsWith("isd_speed"))                return; // Read only
    if (id.startsWith("ipd_state"))                return; // Read only
    if (id.startsWith("ipd_angle"))                return; // Read only
    if (id.startsWith("ed"))                return; // Read only
    if (id.startsWith("eq"))                return; // Read only
    if (id.startsWith("speed_fdbk"))                return; // Read only
    if (id.startsWith("theta_est"))                return; // Read only

    qDebug() << "AddTiConfigLine UNHANDELD: " << id << " value: " << val;
}

/*
		#ifdef TI_TRAPEZUID		
			
		#else
			
		#endif
*/
