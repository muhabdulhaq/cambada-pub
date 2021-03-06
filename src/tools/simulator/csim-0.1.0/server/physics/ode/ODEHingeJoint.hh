/*
 *  Gazebo - Outdoor Multi-Robot Simulator
 *  Copyright (C) 2003  
 *     Nate Koenig & Andrew Howard
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
/* Desc: A body that has a box shape
 * Author: Nate Keonig, Andrew Howard
 * Date: 21 May 2003
 * SVN: $Id: HingeJoint.hh 7039 2008-09-24 18:06:29Z natepak $
 *
 * Modified by: Eurico Pedrosa <efp@ua.p>
 * Date: 10 Fev 2010
 *
 * Modification Notes
 *
 *  The modifications presented by me, have the purpose of
 *  removing the 'rendering' and 'gui' modules from the code base.
 *  The reasons behind this decision are simple, allow gazebo to run
 *  on computers with less gpu capabilities and lessen the the coupling
 *  between simulation and visualization.
 *
 */

#ifndef ODEHINGEJOINT_HH
#define ODEHINGEJOINT_HH

#include "Angle.hh"
#include "Vector3.hh"
#include "Param.hh"
#include "ODEJoint.hh"
#include "HingeJoint.hh"

namespace gazebo
{
  /// \addtogroup gazebo_physics_joints
  /// \{
  /** \defgroup gazebo_hinge_joint Hinge Joint
    
    \brief A single-axis hinge joint in ODE.
  
    \par Attributes
    - body1 (string)
      - Name of the first body to attach to the joint
    - body2 (string)
      - Name of the second body to attach to the joint
    - anchor (string)
      - Name of the body which will act as the anchor to the joint
    - axis (float, tuple)
      - Defines the axis of rotation for the first degree of freedom
      - Default: 0 0 1
    - lowStop (float, degrees)
      - The low stop angle for the first degree of freedom
      - Default: infinity
    - highStop (float, degrees)
      - The high stop angle for the first degree of freedom
      - Default: infinity
    - erp (double)
      - Error reduction parameter. 
      - Default = 0.4
    - cfm (double)
      - Constraint force mixing. 
      - Default = 0.8
  
    \par Example
    \verbatim
    <joint:hinge name="hinge_joint>
      <body1>body1_name</body1>
      <body2>body2_name</body2>
      <anchor>anchor_body</anchor>
      <axis>0 0 1</axis>
      <lowStop>0</lowStop>
      <highStop>30</highStop>
    </joint:hinge>
    \endverbatim
  */
  /// \}
  
  /// \addtogroup gazebo_hinge_joint
  /// \{
  
  ///\brief A single axis hinge joint
  class ODEHingeJoint : public HingeJoint<ODEJoint>
  {
    ///  Constructor
    public: ODEHingeJoint(dWorldID worldId);
  
    /// Destructor
    public: virtual ~ODEHingeJoint();
  
    /// \brief Load joint
    protected: virtual void Load(XMLConfigNode *node);

    /// Get the anchor point
    public: virtual Vector3 GetAnchor(int index) const;

    /// Set the anchor point
    public: virtual void SetAnchor(int index, const Vector3 &anchor);

    /// Get the axis of rotation
    public: virtual Vector3 GetAxis(int index) const;

    /// Set the axis of rotation
    public: virtual void SetAxis(int index, const Vector3 &axis);
 
    /// Get the angle of rotation
    public: virtual Angle GetAngle(int index) const;
 
    /// \brief Set the velocity of an axis(index).
    public: virtual void SetVelocity(int index, double angle);

    /// \brief Get the rotation rate of an axis(index)
    public: virtual double GetVelocity(int index) const;
 
    /// \brief Set the max allowed force of an axis(index).
    public: virtual void SetMaxForce(int index, double t);

    /// \brief Get the max allowed force of an axis(index).
    public: virtual double GetMaxForce(int index);

    /// \brief Set the torque of a joint.
    public: virtual void SetForce(int index, double torque);

    /// Get the specified parameter
    public: virtual double GetParam( int parameter ) const;
  
    /// Set the parameter to value
    public: virtual void SetParam( int parameter, double value);
  };

  /// \}
  
}
#endif

