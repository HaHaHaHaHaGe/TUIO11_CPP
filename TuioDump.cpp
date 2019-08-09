/*
	TUIO C++ Example - part of the reacTIVision project
	http://reactivision.sourceforge.net/

	Copyright (c) 2005-2017 Martin Kaltenbrunner <martin@tuio.org>

	Permission is hereby granted, free of charge, to any person obtaining
	a copy of this software and associated documentation files
	(the "Software"), to deal in the Software without restriction,
	including without limitation the rights to use, copy, modify, merge,
	publish, distribute, sublicense, and/or sell copies of the Software,
	and to permit persons to whom the Software is furnished to do so,
	subject to the following conditions:

	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.

	Any person wishing to distribute modifications to the Software is
	requested to send the modifications to the original developer so that
	they can be incorporated into the canonical version.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
	IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
	ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
	CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
	WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "TuioDump.h"

void(*addTuioObject_ptr)(int, long, int, float, float, float);
void(*updateTuioObject_ptr)(int, long, int, float, float, float, float, float, float, float);
void(*removeTuioObject_ptr)(int, long, int);
void(*addTuioCursor_ptr)(int, long, int, float, float);
void(*updateTuioCursor_ptr)(int, long, int, float, float, float, float);
void(*removeTuioCursor_ptr)(int, long, int);
void(*addTuioBlob_ptr)(int, long, int, float, float, float, float, float, float);
void(*updateTuioBlob_ptr)(int, long, int, float, float, float, float, float, float, float, float, float, float);
void(*removeTuioBlob_ptr)(int, long, int);


void TuioDump::addTuioObject(TuioObject *tobj) {
	addTuioObject_ptr(tobj->getSymbolID(), tobj->getSessionID(), tobj->getTuioSourceID(), tobj->getX(), tobj->getY(), tobj->getAngle());
	//std::cout << "add obj " << tobj->getSymbolID() << " (" << tobj->getSessionID() << "/"<<  tobj->getTuioSourceID() << ") "<< tobj->getX() << " " << tobj->getY() << " " << tobj->getAngle() << std::endl;
}

void TuioDump::updateTuioObject(TuioObject *tobj) {
	updateTuioObject_ptr(tobj->getSymbolID(), tobj->getSessionID(), tobj->getTuioSourceID(), tobj->getX(), tobj->getY(), tobj->getAngle(),
						tobj->getMotionSpeed(), tobj->getRotationSpeed(), tobj->getMotionAccel(), tobj->getRotationAccel());

	//std::cout << "set obj " << tobj->getSymbolID() << " (" << tobj->getSessionID() << "/"<<  tobj->getTuioSourceID() << ") "<< tobj->getX() << " " << tobj->getY() << " " << tobj->getAngle() 
	//			<< " " << tobj->getMotionSpeed() << " " << tobj->getRotationSpeed() << " " << tobj->getMotionAccel() << " " << tobj->getRotationAccel() << std::endl;
}

void TuioDump::removeTuioObject(TuioObject *tobj) {
	removeTuioObject_ptr(tobj->getSymbolID(), tobj->getSessionID(), tobj->getTuioSourceID());
	//std::cout << "del obj " << tobj->getSymbolID() << " (" << tobj->getSessionID() << "/"<<  tobj->getTuioSourceID() << ")" << std::endl;
}

void TuioDump::addTuioCursor(TuioCursor *tcur) {
	addTuioCursor_ptr(tcur->getCursorID(), tcur->getSessionID(), tcur->getTuioSourceID(), tcur->getX(), tcur->getY());

	//std::cout << "add cur " << tcur->getCursorID() << " (" <<  tcur->getSessionID() << "/"<<  tcur->getTuioSourceID() << ") " << tcur->getX() << " " << tcur->getY() << std::endl;
}

void TuioDump::updateTuioCursor(TuioCursor *tcur) {
	updateTuioCursor_ptr(tcur->getCursorID(), tcur->getSessionID(), tcur->getTuioSourceID(), tcur->getX(), tcur->getY(), tcur->getMotionSpeed(), tcur->getMotionAccel());

	//std::cout << "set cur " << tcur->getCursorID() << " (" <<  tcur->getSessionID() << "/"<<  tcur->getTuioSourceID() << ") " << tcur->getX() << " " << tcur->getY() 
	//			<< " " << tcur->getMotionSpeed() << " " << tcur->getMotionAccel() << " " << std::endl;
}

void TuioDump::removeTuioCursor(TuioCursor *tcur) {
	removeTuioCursor_ptr(tcur->getCursorID(), tcur->getSessionID(), tcur->getTuioSourceID());
	//std::cout << "del cur " << tcur->getCursorID() << " (" <<  tcur->getSessionID() << "/"<<  tcur->getTuioSourceID() << ")" << std::endl;
}

void TuioDump::addTuioBlob(TuioBlob *tblb) {
	addTuioBlob_ptr(tblb->getBlobID(), tblb->getSessionID(), tblb->getTuioSourceID(), tblb->getX(), tblb->getY(), tblb->getAngle(), tblb->getWidth(), tblb->getHeight(), tblb->getArea());
	//std::cout << "add blb " << tblb->getBlobID() << " (" << tblb->getSessionID() << "/"<<  tblb->getTuioSourceID() << ") "<< tblb->getX() << " " << tblb->getY() << " " << tblb->getAngle() << " " << tblb->getWidth() << " " << tblb->getHeight() << " " << tblb->getArea() << std::endl;
}

void TuioDump::updateTuioBlob(TuioBlob *tblb) {
	updateTuioBlob_ptr(tblb->getBlobID(), tblb->getSessionID(), tblb->getTuioSourceID(), tblb->getX(), tblb->getY(), tblb->getAngle(), tblb->getWidth(), tblb->getHeight(), tblb->getArea(),
		tblb->getMotionSpeed(), tblb->getRotationSpeed(), tblb->getMotionAccel(), tblb->getRotationAccel());

	//std::cout << "set blb " << tblb->getBlobID() << " (" << tblb->getSessionID() << "/"<<  tblb->getTuioSourceID() << ") "<< tblb->getX() << " " << tblb->getY() << " " << tblb->getAngle() << " "<< tblb->getWidth() << " " << tblb->getHeight() << " " << tblb->getArea() 
	//<< " " << tblb->getMotionSpeed() << " " << tblb->getRotationSpeed() << " " << tblb->getMotionAccel() << " " << tblb->getRotationAccel() << std::endl;
}

void TuioDump::removeTuioBlob(TuioBlob *tblb) {
	removeTuioBlob_ptr(tblb->getBlobID(), tblb->getSessionID(), tblb->getTuioSourceID());
	//std::cout << "del blb " << tblb->getBlobID() << " (" << tblb->getSessionID() << "/"<<  tblb->getTuioSourceID() << ")" << std::endl;
}

void  TuioDump::refresh(TuioTime frameTime) {
	//std::cout << "refresh " << frameTime.getTotalMilliseconds() << std::endl;
}


TuioClient* client = nullptr;


extern "C" __declspec(dllexport) void Call_FuncInit(	void(*a)(int, long, int, float, float, float),
														void(*b)(int, long, int, float, float, float, float, float, float, float),
														void(*c)(int, long, int),
														void(*d)(int, long, int, float, float),
														void(*e)(int, long, int, float, float, float, float),
														void(*f)(int, long, int),
														void(*g)(int, long, int, float, float, float, float, float, float),
														void(*h)(int, long, int, float, float, float, float, float, float, float, float, float, float),
														void(*i)(int, long, int))
{
	addTuioObject_ptr = a;
	updateTuioObject_ptr = b;
	removeTuioObject_ptr = c;
	addTuioCursor_ptr = d;
	updateTuioCursor_ptr = e;
	removeTuioCursor_ptr = f;
	addTuioBlob_ptr = g;
	updateTuioBlob_ptr = h;
	removeTuioBlob_ptr = i;
}


extern "C" __declspec(dllexport) void Tuio_Deinit()
{
	if (client != nullptr)
		client->disconnect();
	client = nullptr;
}
extern "C" __declspec(dllexport) void Tuio_UDPinit(int port)
{
	if (client != nullptr)
		Tuio_Deinit();
	OscReceiver *osc_receiver;
	osc_receiver = new UdpReceiver(port);
	TuioDump dump;
	client = new TuioClient(osc_receiver);
	client->addTuioListener(&dump);
	client->connect(false);
}

extern "C" __declspec(dllexport) void Tuio_TCPinit(char* ip, int port)
{
	if (client != nullptr)
		Tuio_Deinit();
	OscReceiver *osc_receiver;
	osc_receiver = new TcpReceiver(ip, port);
	TuioDump dump;
	client = new TuioClient(osc_receiver);
	client->addTuioListener(&dump);
	client->connect(false);
	
}



//int main(int argc, char* argv[])
//{
//	//init(argc, argv);
//	_port = 3333;
//	OscReceiver *osc_receiver;
//	if (_udp) osc_receiver = new UdpReceiver(_port);
//	else {
//		if (_address=="incoming") osc_receiver = new TcpReceiver(_port);
//		else osc_receiver = new TcpReceiver(_address.c_str(), _port);
//	}
//	TuioDump dump;
//	TuioClient client(osc_receiver);
//	client.addTuioListener(&dump);
//	client.connect(true);
//
//	delete osc_receiver;
//	return 0;
//}


