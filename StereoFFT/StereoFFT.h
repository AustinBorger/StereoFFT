/*
** Copyright (C) 2015 Austin Borger <aaborger@gmail.com>
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
** API documentation is available here:
**		https://github.com/AustinBorger/StereoFFT
*/

#pragma once

#include <Windows.h>
#include <comdef.h>

/* The type of window function to use. */
enum STEREO_FFT_WINDOW_FUNCTION {
	STEREO_FFT_WINDOW_FUNCTION_RECTANGLE,
	STEREO_FFT_WINDOW_FUNCTION_TRIANGLE,
	STEREO_FFT_WINDOW_FUNCTION_WELCH,
	STEREO_FFT_WINDOW_FUNCTION_HANNING,
	STEREO_FFT_WINDOW_FUNCTION_HAMMING,
	STEREO_FFT_WINDOW_FUNCTION_BLACKMAN,
	STEREO_FFT_WINDOW_FUNCTION_NUTTALL,
	STEREO_FFT_WINDOW_FUNCTION_BLACKMAN_NUTTALL,
	STEREO_FFT_WINDOW_FUNCTION_BLACKMAN_HARRIS,
	STEREO_FFT_WINDOW_FUNCTION_FLAT_TOP,
	STEREO_FFT_WINDOW_FUNCTION_COSINE,
	STEREO_FFT_WINDOW_FUNCTION_GAUSSIAN,
	STEREO_FFT_WINDOW_FUNCTION_CONFINED_GAUSSIAN,
	STEREO_FFT_WINDOW_FUNCTION_DOLPH_CHEBYSHEV
};

/* FFT Descriptor */
struct STEREO_FFT_DESC {
	UINT NumSamples; //The number of input samples (number of bins * 2)
	STEREO_FFT_WINDOW_FUNCTION WindowFunction; //The window function used by the FFT
};

/* The StereoFFT interface. */
struct __declspec(uuid("6ec6f647-b334-40d5-ab37-45b5b76ba4ac")) IStereoFFT : public IUnknown {
	/* Updates the history buffer with new information.
	** [Buffer] must be in stereo-interleaved format.
	** [BufferFrames] is the number of stereo samples in the buffer. */
	virtual VOID STDMETHODCALLTYPE Post(PFLOAT Buffer, UINT BufferFrames) PURE;

	/* Processes the data in the history buffer, generating all statistics.
	** Note that this will apply a high-quality window to your data, so there is no
	** need to pre-calculate your own. */
	virtual VOID STDMETHODCALLTYPE Process() PURE;

	/* Sets the window function used by the FFT. */
	virtual VOID STDMETHODCALLTYPE SetWindowFunction(STEREO_FFT_WINDOW_FUNCTION WindowFunction) PURE;

	/* Returns the window function currently being used by the FFT. */
	virtual STEREO_FFT_WINDOW_FUNCTION STDMETHODCALLTYPE GetWindowFunction() PURE;

	/* Returns the number of samples being operated on. */
	virtual UINT STDMETHODCALLTYPE GetNumSamples() PURE;

	/* Returns the number of FFT bins generated by a transform. */
	virtual UINT STDMETHODCALLTYPE GetNumBins() PURE;

	/* Returns the history buffer in stereo-interleaved format. */
	virtual CONST PFLOAT STDMETHODCALLTYPE GetHistoryBuffer() PURE;

	/* Returns the left mix buffer. */
	virtual CONST PFLOAT STDMETHODCALLTYPE GetLeftMix() PURE;

	/* Returns the right mix buffer. */
	virtual CONST PFLOAT STDMETHODCALLTYPE GetRightMix() PURE;

	/* Returns the mid mix buffer. */
	virtual CONST PFLOAT STDMETHODCALLTYPE GetMidMix() PURE;

	/* Returns the side mix buffer. */
	virtual CONST PFLOAT STDMETHODCALLTYPE GetSideMix() PURE;

	/* Returns the left FFT power spectrum. */
	virtual CONST PFLOAT STDMETHODCALLTYPE GetLeftTransform() PURE;

	/* Returns the right FFT power spectrum. */
	virtual CONST PFLOAT STDMETHODCALLTYPE GetRightTransform() PURE;

	/* Returns the mid FFT power spectrum. */
	virtual CONST PFLOAT STDMETHODCALLTYPE GetMidTransform() PURE;

	/* Returns the side FFT power spectrum. */
	virtual CONST PFLOAT STDMETHODCALLTYPE GetSideTransform() PURE;

	/* Returns the left DC offset. */
	virtual FLOAT STDMETHODCALLTYPE GetLeftDCOffset() PURE;

	/* Returns the right DC offset. */
	virtual FLOAT STDMETHODCALLTYPE GetRightDCOffset() PURE;

	/* Returns the mid DC offset. */
	virtual FLOAT STDMETHODCALLTYPE GetMidDCOffset() PURE;

	/* Returns the side DC offset. */
	virtual FLOAT STDMETHODCALLTYPE GetSideDCOffset() PURE;
};

#ifdef _STEREO_FFT_DLL_PROJECT
	#define _STEREO_FFT_EXPORT_TAG __declspec(dllexport)
#else
	#define _STEREO_FFT_EXPORT_TAG __declspec(dllimport)
#endif

/* Creates the analysis object. */
extern "C" HRESULT _STEREO_FFT_EXPORT_TAG CreateStereoFFT (
	const STEREO_FFT_DESC* pDesc,
	IStereoFFT** ppAudioAnalysis
);