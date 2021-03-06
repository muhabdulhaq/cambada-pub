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
/* Desc: An ODE ball joint
 * Author: Nate Keonig
 * Date: 13 Oct 2009
 * SVN: $Id: BallJoint.hh 7039 2008-09-24 18:06:29Z natepak $
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

#ifndef ODEBALLJOINT_HH
#define ODEBALLJOINT_HH

#include "BallJoint.hh"
#include "ODEJoint.hh"

namespace gazebo
{
  
  /// \addtogroup gazebo_physics_joints
  /// \{
  /** \defgroup gazebo_ball_joint Ball Joint
  
    \brief A ball joint
  
    \par Attributes
    - body1 (string)
      - Name of the first body to attach to the joint
    - body2 (string)
      - Name of the second body to attach to the joint
    - anchor (string)
      - Name of the body which will act as the anchor to the joint
    - erp (double)
      - Error reduction parameter. Default = 0.4
    - cfm (double)
      - Constraint force mixing. Default = 0.8
  
    \par Example
    \verbatim
    <joint:ball name="ball_joint>
      <body1>body1_name</body1>
      <body2>body2_name</body2>
      <anchor>anchor_body</anchor>
    </joint:ball>
    \endverbatim
  */
  /// \}
  /// \addtogroup gazebo_ball_joint
  /// \{
  
  /// \brief A ball joint
  class ODEBallJoint : public BallJoint<ODEJoint>
  {
    /// \brief Constructor
    public: ODEBallJoint( dWorldID worldId );
  
    /// \brief Destructor
    public: virtual ~ODEBallJoint();
  
    /// \brief Get joint's anchor point
    public: virtual Vector3 GetAnchor(int index) const;
  
    /// \brief Set joint's anchor point
    public: virtual void SetAnchor( int index, const Vector3 &anchor );

    /// \brief Get the axis of rotation
    public: virtual Vector3 GetAxis(int index) const {}

    /// \brief Set the velocity of an axis(index).
    public: virtual void SetVelocity(int index, double angle) {}

    /// \brief Get the rotation rate of an axis(index)
    public: virtual double GetVelocity(int index) const {}

    /// \brief Get the max allowed force of an axis(index).
    public: virtual double GetMaxForce(int index) {}

    /// \brief Set the max allowed force of an axis(index).
    public: virtual void SetMaxForce(int index, double t) {}

    /// \brief Get the angle of rotation of an axis(index)
    public: virtual Angle GetAngle(int index) const {}
 
  };
  
  /// \}
}

#endif
