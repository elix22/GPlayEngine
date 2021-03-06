//
// SPARK particle engine
//
// Copyright (C) 2008-2011 - Julien Fryer - julienfryer@gmail.com
// Copyright (C) 2017 - Frederic Martin - fredakilla@gmail.com
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#include <SPARK_Core.h>
#include "Extensions/Modifiers/SPK_Rotator.h"

namespace SPK
{
	void Rotator::modify(Group& group,DataSet* dataSet,float deltaTime) const
	{
		if (group.isEnabled(PARAM_ANGLE) && group.isEnabled(PARAM_ROTATION_SPEED))
			for (GroupIterator particleIt(group); !particleIt.end(); ++particleIt)
			{
				float angle = particleIt->getParamNC(PARAM_ANGLE) + particleIt->getParamNC(PARAM_ROTATION_SPEED) * deltaTime;
				particleIt->setParamNC(PARAM_ANGLE,angle);
			}
		else
			SPK_LOG_WARNING("Rotator::modify(Group&,DataSet*,float) - PARAM_ANGLE and PARAM_ROTATION_SPEED must be enabled to use a rotator");
	}
}
